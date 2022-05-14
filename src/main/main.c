#include <lib/chessviz.h>

int w_pass = 0;   // En passant for White
int w_x = -1;     // Pawn possition for en passant
int b_pass = 0;   // En passant for Black
int b_x = -1;     // Pawn possition for en passant
int wk_move = 0;  // Number of white king move for roque
int bk_move = 0;  // Number of black king move for roque
int wra_move = 0; // Number of white left rook move for roque
int bra_move = 0; // Number of black left rook move for roque
int wrh_move = 0; // Number of white right rook move for roque
int brh_move = 0; // Number of black right rook move for roque

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
            if (CheckW(board)) {
                ErrorC(2);
                break;
            }
            w_pass = 0;
            Black(board, b);
            if (CheckB(board)) {
                ErrorC(2);
                break;
            }
            b_pass = 0;
        } else {
            ErrorC(1);
            break;
        }
    }
    return 0;
}
