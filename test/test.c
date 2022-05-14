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
