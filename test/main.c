#define CTEST_MAIN

#include "../thirdparty/ctest.h"

// Constant
int w_pass = 0;   // En passant for White
int w_x = -1;     // Pawn possition for en passant
int b_pass = 0;   // En passant for Black
int b_x = -1;     // Pawn possition for en passant

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
