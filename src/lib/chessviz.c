#include <lib/chessviz.h>

extern int w_pass;   // En passant for White
extern int w_x;      // Pawn possition for en passant
extern int b_pass;   // En passant for Black
extern int b_x;      // Pawn possition for en passant
extern int wk_move;  // Number of white king move for roque
extern int bk_move;  // Number of black king move for roque
extern int wra_move; // Number of white left rook move for roque
extern int bra_move; // Number of black left rook move for roque
extern int wrh_move; // Number of white right rook move for roque
extern int brh_move; // Number of black right rook move for roque

char white_piece[6] = {'Q', 'K', 'B', 'N', 'R', 'P'};
char black_piece[6] = {'q', 'k', 'b', 'n', 'r', 'p'};

void Create(char board[8][8])
{
    char mas[8][8] = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = mas[i][j];
        }
    }
}

void Show(char c[8][8])
{
    printf("   ");
    for (int i = 0; i < 8; i++) {
        printf(" %c", 'a' + i);
    }
    printf(" \n");

    printf("   -");
    for (int i = 0; i < 8; i++) {
        printf("--");
    }
    printf("\n");

    for (int i = 7; i >= 0; i--) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            printf(" %c", c[i][j]);
        }
        printf(" | %d \n", i + 1);
    }

    printf("   -");
    for (int i = 0; i < 8; i++) {
        printf("--");
    }
    printf("\n");

    printf("   ");
    for (int i = 0; i < 8; i++) {
        printf(" %c", 'a' + i);
    }
    printf("\n");
}

void Error()
{
    printf("\n Invalid input \n");
    exit(1);
}
void ErrorC(int n)
{
    printf("\n Invalid input, code: %d \n", n);
    exit(1);
}

int ParseX(char n)
{
    int x = n - 97;
    return x;
}
int ParseY(char n)
{
    int y = n - 49;
    return y;
}

int CheckW(char board[8][8])
{
    int k1 = -1;
    int k2 = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'K') {
                k1 = i;
                k2 = j;
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int x;
            int y;
            int q1;
            int q2;
            int flag = 0;
            switch (board[i][j]) {
            case 'q':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1)
                           || (y != 0 && x != 0))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'b':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                while ((q1 != k1 && q2 != k2) && (y != 0 && x != 0)) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'r':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'n':
                x = 0;
                y = 0;
                x = abs(k1 - i);
                y = abs(k2 - j);
                if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
                    return 1;
                }
                break;
            case 'p':
                x = 0;
                y = 0;
                x = i - k1;
                y = abs(j - k2);
                if (y == 1 && x == 1) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

int CheckB(char board[8][8])
{
    int k1 = -1;
    int k2 = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'k') {
                k1 = i;
                k2 = j;
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int x;
            int y;
            int q1;
            int q2;
            int flag = 0;
            switch (board[i][j]) {
            case 'Q':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1)
                           || (y != 0 && x != 0))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'B':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (abs(q1 - k1) == abs(q2 - k2)) {
                    x = (k1 - q1) / abs(q1 - k1);
                    y = (k2 - q2) / abs(q2 - k2);
                }
                while ((q1 != k1 && q2 != k2) && (y != 0 && x != 0)) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'R':
                x = 0;
                y = 0;
                q1 = i;
                q2 = j;
                if (i == k1) {
                    y = (k2 - q2) / abs(q2 - k2);
                }
                if (j == k2) {
                    x = (k1 - q1) / abs(q1 - k1);
                }
                while ((q1 != k1 || q2 != k2)
                       && ((x != 0 && q2 == k2) || (y != 0 && q1 == k1))) {
                    q1 += x;
                    q2 += y;
                    if (board[q1][q2] != ' ') {
                        flag++;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
                break;
            case 'N':
                x = 0;
                y = 0;
                x = abs(k1 - i);
                y = abs(k2 - j);
                if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
                    return 1;
                }
                break;
            case 'P':
                x = 0;
                y = 0;
                x = k1 - i;
                y = abs(j - k2);
                if (y == 1 && x == 1) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

void WhitePawn(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= '1' && w[1] <= '8' && (w[2] == '-' || w[2] == 'x')
        && w[3] >= 'a' && w[3] <= 'h' && w[4] >= '1' && w[4] <= '8'
        && (w[5] == '\0' || w[5] == '#')) {
        x1 = ParseX(w[0]);
        y1 = ParseY(w[1]);
        x2 = ParseX(w[3]);
        y2 = ParseY(w[4]);
    } else {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[2] == '-') || (take == 1 && w[2] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'P' && flag == 0) {
        flag = 1;
    }
    if ((x1 == x2 && y1 + 1 == y2) || (x1 == x2 && y1 == 1 && y2 == 3)
        || (board[y2][x2] == 'p' && y1 + 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2))
        || (board[y2 - 1][x2] == 'p' && y1 + 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2) && w_pass == 1 && w_x == x2)) {
        //(Move||Move from 6 to 4 line||Take||En passant)
        if (flag == 0) {
            board[y1][x1] = ' ';
            board[y2][x2] = 'P';
            if (board[y2 - 1][x2] == 'p' && y1 + 1 == y2
                && (x1 + 1 == x2 || x1 - 1 == x2) && w_pass == 1 && w_x == x2) {
                board[y2 - 1][x2] = ' ';
            }
            Show(board);
        }
    } else {
        flag = 1;
    }
    if (flag != 0) {
        ErrorC(3);
    } else {
        if (x1 == x2 && y1 == 1 && y2 == 3) {
            b_pass = 1;
            b_x = x2;
        }
    }
}

void BlackPawn(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= '1' && b[1] <= '8' && (b[2] == '-' || b[2] == 'x')
        && b[3] >= 'a' && b[3] <= 'h' && b[4] >= '1' && b[4] <= '8'
        && (b[5] == '\0' || b[5] == '#')) {
        x1 = ParseX(b[0]);
        y1 = ParseY(b[1]);
        x2 = ParseX(b[3]);
        y2 = ParseY(b[4]);
        // printf("\n Piece: %c on %d %d\n",board[y1][x1],y1,x1);
    } else {
        flag = 1;
    }

    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[2] == '-') || (take == 1 && b[2] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'p' && flag == 0) {
        flag = 1;
    }
    if ((x1 == x2 && y1 - 1 == y2) || (x1 == x2 && y1 == 6 && y2 == 4)
        || (board[y2][x2] == 'P' && y1 - 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2))
        || (board[y2 + 1][x2] == 'P' && y1 - 1 == y2
            && (x1 + 1 == x2 || x1 - 1 == x2) && b_pass == 1 && b_x == x2)) {
        //(Move||Move from 6 to 4 line||Take||En passant)
        if (flag == 0) {
            board[y1][x1] = ' ';
            board[y2][x2] = 'p';
            if (board[y2 + 1][x2] == 'P' && y1 - 1 == y2
                && (x1 + 1 == x2 || x1 - 1 == x2) && b_pass == 1 && b_x == x2) {
                board[y2 + 1][x2] = ' ';
            }
            Show(board);
        }
    } else {
        flag = 1;
    }
    if (flag != 0) {
        ErrorC(3);
    } else {
        if (x1 == x2 && y1 == 6 && y2 == 4) {
            w_pass = 1;
            w_x = x2;
        }
    }
}

void WhiteKing(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8'
        && (w[3] == '-' || w[3] == 'x') && w[4] >= 'a' && w[4] <= 'h'
        && w[5] >= '1' && w[5] <= '8' && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }

    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[3] == '-') || (take == 1 && w[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'K') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 0) || (xs == 0 && ys == 1)
            || (xs == 1 && ys == 1)) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'K';
            if (!CheckW(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'K';
        Show(board);
        wk_move++;
    } else {
        ErrorC(3);
    }
}
void BlackKing(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8'
        && (b[3] == '-' || b[3] == 'x') && b[4] >= 'a' && b[4] <= 'h'
        && b[5] >= '1' && b[5] <= '8' && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }

    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[3] == '-') || (take == 1 && b[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'k') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 0) || (xs == 0 && ys == 1)
            || (xs == 1 && ys == 1)) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'k';
            if (!CheckB(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'k';
        Show(board);
        bk_move++;
    } else {
        ErrorC(3);
    }
}

void WhiteRook(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8'
        && (w[3] == '-' || w[3] == 'x') && w[4] >= 'a' && w[4] <= 'h'
        && w[5] >= '1' && w[5] <= '8' && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }

    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[3] == '-') || (take == 1 && w[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'R') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'R';
            if (!CheckW(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'R';
        Show(board);
        if (x1 == 0 && y1 == 0) {
            wra_move++;
        }
        if (x1 == 7 && y1 == 0) {
            wrh_move++;
        }
    } else {
        ErrorC(3);
    }
}
void BlackRook(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8'
        && (b[3] == '-' || b[3] == 'x') && b[4] >= 'a' && b[4] <= 'h'
        && b[5] >= '1' && b[5] <= '8' && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'r') {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[3] == '-') || (take == 1 && b[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'r') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'r';
            if (!CheckB(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'r';
        Show(board);
        if (x1 == 0 && y1 == 7) {
            bra_move++;
        }
        if (x1 == 7 && y1 == 7) {
            brh_move++;
        }
    } else {
        ErrorC(3);
    }
}

void WhiteBishop(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8'
        && (w[3] == '-' || w[3] == 'x') && w[4] >= 'a' && w[4] <= 'h'
        && w[5] >= '1' && w[5] <= '8' && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'B') {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[3] == '-') || (take == 1 && w[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'B') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == ys) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'B';
            if (!CheckW(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'B';
        Show(board);
    } else {
        ErrorC(3);
    }
}
void BlackBishop(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8'
        && (b[3] == '-' || b[3] == 'x') && b[4] >= 'a' && b[4] <= 'h'
        && b[5] >= '1' && b[5] <= '8' && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }

    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[3] == '-') || (take == 1 && b[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'b') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == ys) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'b';
            if (!CheckB(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'b';
        Show(board);
    } else {
        ErrorC(3);
    }
}

void WhiteKnight(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8'
        && (w[3] == '-' || w[3] == 'x') && w[4] >= 'a' && w[4] <= 'h'
        && w[5] >= '1' && w[5] <= '8' && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[3] == '-') || (take == 1 && w[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'N') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 2) || (xs == 2 && ys == 1)) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'N';
            if (!CheckW(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'N';
        Show(board);
    } else {
        Error();
    }
}
void BlackKnight(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8'
        && (b[3] == '-' || b[3] == 'x') && b[4] >= 'a' && b[4] <= 'h'
        && b[5] >= '1' && b[5] <= '8' && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[3] == '-') || (take == 1 && b[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'n') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if ((xs == 1 && ys == 2) || (xs == 2 && ys == 1)) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'n';
            if (!CheckB(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'n';
        Show(board);
    } else {
        Error();
    }
}

void WhiteQueen(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= 'a' && w[1] <= 'h' && w[2] >= '1' && w[2] <= '8'
        && (w[3] == '-' || w[3] == 'x') && w[4] >= 'a' && w[4] <= 'h'
        && w[5] >= '1' && w[5] <= '8' && (w[6] == '\0' || w[6] == '#')) {
        x1 = ParseX(w[1]);
        y1 = ParseY(w[2]);
        x2 = ParseX(w[4]);
        y2 = ParseY(w[5]);
    } else {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == black_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && w[3] == '-') || (take == 1 && w[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'Q') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0 || xs == ys) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'Q';
            if (!CheckW(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'Q';
        Show(board);
    } else {
        Error();
    }
}
void BlackQueen(char board[8][8], char b[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (b[1] >= 'a' && b[1] <= 'h' && b[2] >= '1' && b[2] <= '8'
        && (b[3] == '-' || b[3] == 'x') && b[4] >= 'a' && b[4] <= 'h'
        && b[5] >= '1' && b[5] <= '8' && (b[6] == '\0' || b[6] == '#')) {
        x1 = ParseX(b[1]);
        y1 = ParseY(b[2]);
        x2 = ParseX(b[4]);
        y2 = ParseY(b[5]);
    } else {
        flag = 1;
    }
    int take = 0;
    for (int i = 0; i < 8; i++) {
        if (board[y2][x2] == white_piece[i]) {
            take = 1;
        }
    }
    if ((board[y2][x2] == ' ' && b[3] == '-') || (take == 1 && b[3] == 'x')) {
        flag = 0;
    } else {
        flag = 1;
    }
    if (board[y1][x1] != 'q') {
        flag = 1;
    }
    if (flag == 0) {
        flag = 1;
        int xs = abs(x1 - x2);
        int ys = abs(y1 - y2);
        if (xs == 0 || ys == 0 || xs == ys) {
            char mas[8][8];
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    mas[i][j] = board[i][j];
                }
            }
            mas[y1][x1] = ' ';
            mas[y2][x2] = 'q';
            if (!CheckB(mas)) {
                flag = 0;
            }
        }
    }
    if (flag == 0) {
        board[y1][x1] = ' ';
        board[y2][x2] = 'q';
        Show(board);
    } else {
        Error();
    }
}

void WhiteRoque(char board[8][8], char w[7])
{
    char mas[8][8];
    int kx = 0;
    int ky = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mas[i][j] = board[i][j];
            if (board[i][j] == 'K') {
                kx = j;
                ky = i;
            }
        }
    }
    if (kx != 4 && ky != 0) {
        ErrorC(3);
    }
    if (wk_move != 0) {
        ErrorC(3);
    }
    if (w[1] == '-' && w[2] == '0' && (w[3] == '\0' || w[3] == '#')) {
        if (wrh_move != 0) {
            ErrorC(3);
        }
        if (board[ky][kx + 1] != ' ' || board[ky][kx + 2] != ' ') {
            ErrorC(3);
        }
        if (board[ky][kx + 3] != 'R') {
            ErrorC(3);
        }
        mas[ky][kx + 1] = 'K';
        mas[ky][kx + 2] = 'K';
        if (CheckW(mas)) {
            ErrorC(3);
        }
        board[ky][kx] = ' ';
        board[ky][kx + 2] = 'K';
        board[ky][kx + 1] = 'R';
        board[ky][kx + 3] = ' ';
        Show(board);
    }
    if (w[1] == '-' && w[2] == '0' && w[3] == '-' && w[4] == '0'
        && (w[5] == '\0' || w[5] == '#')) {
        if (wra_move != 0) {
            ErrorC(3);
        }
        if (board[ky][kx - 1] != ' ' || board[ky][kx - 2] != ' '
            || board[ky][kx - 3] != ' ') {
            ErrorC(3);
        }
        if (board[ky][kx - 4] != 'R') {
            ErrorC(3);
        }
        mas[ky][kx - 1] = 'K';
        mas[ky][kx - 2] = 'K';
        if (CheckW(mas)) {
            ErrorC(3);
        }
        board[ky][kx] = ' ';
        board[ky][kx - 2] = 'K';
        board[ky][kx - 1] = 'R';
        board[ky][kx - 4] = ' ';
        Show(board);
    }
}
void BlackRoque(char board[8][8], char b[7])
{
    char mas[8][8];
    int kx = 0;
    int ky = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mas[i][j] = board[i][j];
            if (board[i][j] == 'k') {
                kx = j;
                ky = i;
            }
        }
    }
    if (kx != 4 && ky != 7) {
        ErrorC(3);
    }
    if (bk_move != 0) {
        ErrorC(3);
    }
    if (b[1] == '-' && b[2] == '0' && (b[3] == '\0' || b[3] == '#')) {
        if (brh_move != 0) {
            ErrorC(3);
        }
        if (board[ky][kx + 1] != ' ' || board[ky][kx + 2] != ' ') {
            ErrorC(3);
        }
        if (board[ky][kx + 3] != 'r') {
            ErrorC(3);
        }
        mas[ky][kx + 1] = 'k';
        mas[ky][kx + 2] = 'k';
        if (CheckB(mas)) {
            ErrorC(3);
        }
        board[ky][kx] = ' ';
        board[ky][kx + 2] = 'k';
        board[ky][kx + 1] = 'r';
        board[ky][kx + 3] = ' ';
        Show(board);
    }
    if (b[1] == '-' && b[2] == '0' && b[3] == '-' && b[4] == '0'
        && (b[5] == '\0' || b[5] == '#')) {
        if (bra_move != 0) {
            ErrorC(3);
        }
        if (board[ky][kx - 1] != ' ' || board[ky][kx - 2] != ' '
            || board[ky][kx - 3] != ' ') {
            ErrorC(3);
        }
        if (board[ky][kx - 4] != 'r') {
            ErrorC(3);
        }
        mas[ky][kx - 1] = 'k';
        mas[ky][kx - 2] = 'k';
        if (CheckB(mas)) {
            ErrorC(3);
        }
        board[ky][kx] = ' ';
        board[ky][kx - 2] = 'k';
        board[ky][kx - 1] = 'r';
        board[ky][kx - 4] = ' ';
        Show(board);
    }
}

void White(char board[8][8], char w[7])
{
    switch (w[0]) {
    case 'Q':
        WhiteQueen(board, w);
        break;
    case 'B':
        WhiteBishop(board, w);
        break;
    case 'N':
        WhiteKnight(board, w);
        break;
    case 'R':
        WhiteRook(board, w);
        break;
    case 'K':
        WhiteKing(board, w);
        break;
    default:
        if (w[0] >= 'a' && w[0] <= 'h') {
            WhitePawn(board, w);

        } else {
            ErrorC(1);
            break;
        }
    }
}

void Black(char board[8][8], char b[7])
{
    switch (b[0]) {
    case 'Q':
        BlackQueen(board, b);
        break;
    case 'B':
        BlackBishop(board, b);
        break;
    case 'N':
        BlackKnight(board, b);
        break;
    case 'R':
        BlackRook(board, b);
        break;
    case 'K':
        BlackKing(board, b);
        break;
    default:
        if (b[0] >= 'a' && b[0] <= 'h') {
            BlackPawn(board, b);
        } else {
            ErrorC(1);
            break;
        }
    }
}

int WinW(char board[8][8], char w[7], int n)
{
    for (int i = 0; i < 7; i++) {
        if (w[i] == '#') {
            printf("\n%d. %s\n", n, w);
            White(board, w);
            w_pass = 0;
            // printf("\n White WIN! \n");
            printf("\n END \n");
            return 1;
        }
    }
    return 0;
}

int WinB(char board[8][8], char w[7], char b[7], int n)
{
    for (int i = 0; i < 7; i++) {
        if (b[i] == '#') {
            printf("\n%d. %s %s \n", n, w, b);
            White(board, w);
            w_pass = 0;
            Black(board, b);
            b_pass = 0;
            // printf("\n Black WIN! \n");
            printf("\n END \n");
            return 1;
        }
    }
    return 0;
}
