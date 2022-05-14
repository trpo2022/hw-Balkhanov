#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chessviz function

void Create(char board[8][8]);
void Show(char c[8][8]);
void Error();
void ErrorC(int n);
int ParseX(char n);
int ParseY(char n);
int CheckW(char board[8][8]);
int CheckB(char board[8][8]);
void WhitePawn(char board[8][8], char w[7]);
void BlackPawn(char board[8][8], char w[7]);
void WhiteKing(char board[8][8], char w[7]);
void BlackKing(char board[8][8], char w[7]);
void WhiteRook(char board[8][8], char w[7]);
void BlackRook(char board[8][8], char w[7]);
void WhiteBishop(char board[8][8], char w[7]);
void BlackBishop(char board[8][8], char w[7]);
void WhiteKnight(char board[8][8], char w[7]);
void BlackKnight(char board[8][8], char w[7]);
void WhiteQueen(char board[8][8], char w[7]);
void BlackQueen(char board[8][8], char w[7]);
void WhiteRoque(char board[8][8], char w[7]);
void BlackRoque(char board[8][8], char b[7]);
void White(char board[8][8], char w[7]);
void Black(char board[8][8], char b[7]);
int WinW(char board[8][8], char w[7], int n);
int WinB(char board[8][8], char w[7], char b[7], int n);
