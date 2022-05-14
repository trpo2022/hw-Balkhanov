#define CTEST_MAIN

#include "../thirdparty/ctest.h"

// Constant
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

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
