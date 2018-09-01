#define _CRT_SECURE_NO_WARNINGS
#include "queueADT.h"
#include "pos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
//func
void read_maze();
void print_maze();

// // //
int maze[MAX][MAX];
int mazesize;
int main()
{
	read_maze();
	printf("# original maze\n");
	print_maze();


}

void read_maze()
{
	FILE *fp = fopen("maze.txt", "r");
	if (fp == NULL)err_msg("error in reading maze.txt");
	fscanf(fp, "%d", &mazesize);
	for (int i = 0; i < mazesize; i++)
		for (int j = 0; j < mazesize; j++)
			fscanf(fp, "%d", &maze[i][j]);
	fclose(fp);
}

void print_maze()
{
	for (int i = 0; i < mazesize; i++)
	{
		for (int j = 0; j < mazesize; j++)
			printf("%3d ", maze[i][j]);
		puts("");
	}
	puts("");
}