#include <lib/chessviz.h>

int w_pass = 0; // En passant for White
int w_x = -1;   // Pawn possition for en passant
int b_pass = 0; // En passant for Black
int b_x = -1;   // Pawn possition for en passant

int main()
{
    char board[8][8];
    int MoveNum = 0;
    Create(board);
    Show(board);
    // freopen("input.txt","r",stdin);
    int n = 0;
    char w[7];
    char b[7];
    while (n == MoveNum) {
        MoveNum += 1;
        scanf("%d. ", &n);
        if (MoveNum == n) {
            scanf("%s", w);
            if (WinW(board, w, n)) {
                break;
            }
            scanf("%s", b);
            if (WinB(board, w, b, n)) {
                break;
            }
            printf("\n%d. %s %s \n", n, w, b);
            White(board, w);
            w_pass = 0;
            Black(board, b);
            b_pass = 0;
        } else {
            Error();
            break;
        }
    }
    return 0;
}
