#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chessviz function

void Create(char board[8][8]);
void Show(char c[8][8]);
void Error();
int ParseX(char n);
int ParseY(char n);
void WhitePawn(char board[8][8], char w[7]);
void BlackPawn(char board[8][8], char b[7]);
void White(char board[8][8], char w[7]);
void Black(char board[8][8], char b[7]);
int WinW(char board[8][8], char w[7], int n);
int WinB(char board[8][8], char w[7], char b[7], int n);
