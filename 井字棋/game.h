#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
//���峣���к���
#define ROW 3
#define COL 3
//��������
void initboard(char board[ROW][COL], int row,int col);
void Displayboard(char board[ROW][COL], int roe, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove1(char board[ROW][COL], int row, int col);
void computermove_defense(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);
void computermove_attack(char board[ROW][COL],int row,int col);
void computer_joke(char board[ROW][COL], int row, int col);
