#include "../src/lib/chessviz.h"

#include "../thirdparty/ctest.h"

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

CTEST(fill_board, board)
{
    char board[8][8];
    Create(board);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ASSERT_EQUAL(mas[i][j], board[i][j]);
        }
    }
}

CTEST(parse, x)
{
    char c = 'a';
    int exp = 0;
    int real = ParseX(c);
    ASSERT_EQUAL(exp, real);
}

CTEST(parse, y)
{
    char c = '1';
    int exp = 0;
    int real = ParseY(c);
    ASSERT_EQUAL(exp, real);
}

CTEST(check, w_false)
{
    int exp = 0;
    int real = CheckW(mas);
    ASSERT_EQUAL(exp, real);
}

CTEST(check, b_false)
{
    int exp = 0;
    int real = CheckB(mas);
    ASSERT_EQUAL(exp, real);
}

CTEST(check, w_true)
{
    int exp = 0;
    char board[8][8];
    Create(board);
    board[1][4] = 'Q';
    int real = CheckW(board);
    ASSERT_EQUAL(exp, real);
}
CTEST(check, b_true)
{
    int exp = 0;
    char board[8][8];
    Create(board);
    board[6][4] = 'q';
    int real = CheckB(board);
    ASSERT_EQUAL(exp, real);
}

CTEST(movement, white_roque)
{
    char board[8][8];
    Create(board);
    board[0][5] = ' ';
    board[0][6] = ' ';
    char w[7] = {'0', '-', '0', '\0'};
    WhiteRoque(board, w);
    ASSERT_EQUAL(board[0][5], 'R');
    ASSERT_EQUAL(board[0][6], 'K');
}

CTEST(movement, black_roque)
{
    char board[8][8];
    Create(board);
    board[7][5] = ' ';
    board[7][6] = ' ';
    char b[7] = {'0', '-', '0', '\0'};
    BlackRoque(board, b);
    ASSERT_EQUAL(board[7][5], 'r');
    ASSERT_EQUAL(board[7][6], 'k');
}

CTEST(movement, white_pawn)
{
    char board[8][8];
    Create(board);
    char w[7] = {'e', '2', '-', 'e', '4', '\0'};
    WhitePawn(board, w);
    ASSERT_EQUAL(board[1][4], ' ');
    ASSERT_EQUAL(board[3][4], 'P');
}

CTEST(movement, black_pawn)
{
    char board[8][8];
    Create(board);
    char b[7] = {'e', '7', '-', 'e', '5', '\0'};
    BlackPawn(board, b);
    ASSERT_EQUAL(board[6][4], ' ');
    ASSERT_EQUAL(board[4][4], 'p');
}

CTEST(movement, white_king)
{
    char board[8][8];
    Create(board);
    board[1][4] = ' ';
    char w[7] = {'K', 'e', '1', '-', 'e', '2', '\0'};
    WhiteKing(board, w);
    ASSERT_EQUAL(board[1][4], 'K');
    ASSERT_EQUAL(board[0][4], ' ');
}

CTEST(movement, black_king)
{
    char board[8][8];
    Create(board);
    board[6][4] = ' ';
    char b[7] = {'K', 'e', '8', '-', 'e', '7', '\0'};
    BlackKing(board, b);
    ASSERT_EQUAL(board[6][4], 'k');
    ASSERT_EQUAL(board[7][4], ' ');
}

CTEST(movement, white_queen)
{
    char board[8][8];
    Create(board);
    board[1][4] = ' ';
    char w[7] = {'Q', 'd', '1', '-', 'e', '2', '\0'};
    WhiteQueen(board, w);
    ASSERT_EQUAL(board[1][4], 'Q');
    ASSERT_EQUAL(board[0][3], ' ');
}

CTEST(movement, black_queen)
{
    char board[8][8];
    Create(board);
    board[6][4] = ' ';
    char b[7] = {'Q', 'd', '8', '-', 'e', '7', '\0'};
    BlackQueen(board, b);
    ASSERT_EQUAL(board[6][4], 'q');
    ASSERT_EQUAL(board[7][3], ' ');
}

CTEST(movement, white_knight)
{
    char board[8][8];
    Create(board);
    char w[7] = {'N', 'b', '1', '-', 'c', '3', '\0'};
    WhiteKnight(board, w);
    ASSERT_EQUAL(board[2][2], 'N');
    ASSERT_EQUAL(board[0][1], ' ');
}

CTEST(movement, black_knight)
{
    char board[8][8];
    Create(board);
    char b[7] = {'N', 'b', '8', '-', 'c', '6', '\0'};
    BlackKnight(board, b);
    ASSERT_EQUAL(board[5][2], 'n');
    ASSERT_EQUAL(board[7][1], ' ');
}

CTEST(movement, white_rook)
{
    char board[8][8];
    Create(board);
    board[1][0] = ' ';
    char w[7] = {'N', 'a', '1', '-', 'a', '3', '\0'};
    WhiteRook(board, w);
    ASSERT_EQUAL(board[2][0], 'R');
    ASSERT_EQUAL(board[0][0], ' ');
}

CTEST(movement, black_rook)
{
    char board[8][8];
    Create(board);
    board[6][0] = ' ';
    char b[7] = {'N', 'a', '8', '-', 'a', '6', '\0'};
    BlackRook(board, b);
    ASSERT_EQUAL(board[5][0], 'r');
    ASSERT_EQUAL(board[7][0], ' ');
}

CTEST(movement, white_bishop)
{
    char board[8][8];
    Create(board);
    board[1][4] = ' ';
    char w[7] = {'B', 'f', '1', '-', 'd', '3', '\0'};
    WhiteBishop(board, w);
    ASSERT_EQUAL(board[2][3], 'B');
    ASSERT_EQUAL(board[0][5], ' ');
}

CTEST(movement, black_bishop)
{
    char board[8][8];
    Create(board);
    board[6][4] = ' ';
    char b[7] = {'N', 'f', '8', '-', 'd', '6', '\0'};
    BlackBishop(board, b);
    ASSERT_EQUAL(board[5][3], 'b');
    ASSERT_EQUAL(board[7][5], ' ');
}
