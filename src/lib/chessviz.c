#include <lib/chessviz.h>

extern int w_pass; // En passant for White
extern int w_x;    // Pawn possition for en passant
extern int b_pass; // En passant for Black
extern int b_x;    // Pawn possition for en passant

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

void WhitePawn(char board[8][8], char w[7])
{
    int flag = 0;
    int x1, y1, x2, y2;
    if (w[1] >= '1' && w[1] <= '8' && w[2] == '-' && w[3] >= 'a' && w[3] <= 'h'
        && w[4] >= '1' && w[4] <= '8' && (w[5] == '\0' || w[5] == '#')) {
        x1 = ParseX(w[0]);
        y1 = ParseY(w[1]);
        x2 = ParseX(w[3]);
        y2 = ParseY(w[4]);
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
        Error();
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
    if (b[1] >= '1' && b[1] <= '8' && b[2] == '-' && b[3] >= 'a' && b[3] <= 'h'
        && b[4] >= '1' && b[4] <= '8' && (b[5] == '\0' || b[5] == '#')) {
        x1 = ParseX(b[0]);
        y1 = ParseY(b[1]);
        x2 = ParseX(b[3]);
        y2 = ParseY(b[4]);
        // printf("\n Piece: %c on %d %d\n",board[y1][x1],y1,x1);
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
        Error();
    } else {
        if (x1 == x2 && y1 == 6 && y2 == 4) {
            w_pass = 1;
            w_x = x2;
        }
    }
}

void White(char board[8][8], char w[7])
{
    switch (w[0]) {
    case 'Q':
        break;
    case 'B':
        break;
    case 'N':
        break;
    case 'R':
        break;
    case 'K':
        break;
    default:
        if (w[0] >= 'a' && w[0] <= 'h') {
            WhitePawn(board, w);

        } else {
            Error();
            break;
        }
    }
}

void Black(char board[8][8], char b[7])
{
    switch (b[0]) {
    case 'q':
        break;
    case 'b':
        if (b[5] == '\0') {
            BlackPawn(board, b);
        }
        break;
    case 'n':
        break;
    case 'r':
        break;
    case 'k':
        break;
    default:
        if (b[0] >= 'a' && b[0] <= 'h') {
            BlackPawn(board, b);
        } else {
            Error();
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
            printf("\n White WIN! \n");
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
            printf("\n Black WIN! \n");
            return 1;
        }
    }
    return 0;
}
