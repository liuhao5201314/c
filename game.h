#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9//定义棋盘大小
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10//定义雷的个数

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);//进行初始的声明

void DisplayBoard(char board[ROWS][COLS], int row, int col);//因为mind已经为11*11所以我们接受必须使用相同的进行接收所以不能使用char board[ROW][COL]

void SetMind(char board[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS],char board[ROWS][COLS], int row, int col);
