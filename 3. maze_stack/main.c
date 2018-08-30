#define _CRT_SECURE_NO_WARNINGS
#include "pos.h"
#include "stackADT.h"
#include <stdio.h>
#define MAX 100

//func
void read_maze(char *filename);
void print_maze();
// // // // //

int maze[MAX][MAX];
int mazesize;

int main()
{
	read_maze("maze.txt");
	printf("# original \n");
	print_maze();
}



void read_maze(char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("can't read file\n");
		exit(1);
	}
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
			printf("%d ", maze[i][j]);
		puts("");
	}
	puts("");
}