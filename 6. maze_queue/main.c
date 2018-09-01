#define _CRT_SECURE_NO_WARNINGS
#include "queueADT.h"
#include "pos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

#define PATH 0
#define WALL 1

//func
void read_maze();
void print_maze();
bool movable(Position cur, int dir);
// // //
int maze[MAX][MAX];
int mazesize;
int main()
{
	read_maze();
	printf("# original maze\n");
	print_maze();
	Queue q = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;
	enqueue(q, cur);
	maze[cur.x][cur.y] = -1;
	bool found = false;
	while (!is_empty(q))
	{
		cur = dequeue(q);
		for (int dir = 0; dir < 4; dir++)
		{
			if (movable(cur, dir))
			{
				Position p = move_to(cur, dir);
				maze[p.x][p.y] = maze[cur.x][cur.y] - 1;
				if (p.x == mazesize - 1 && p.y == mazesize - 1)
				{
					printf("found the path\n");
					found = true;
					break;
				}
				enqueue(q, p);
			}
		}
	}
	printf("# solved maze\n");
	print_maze();
}

bool movable(Position cur, int dir)
{
	Position next = move_to(cur, dir);
	if (next.x<0 || next.y<0 || next.x>mazesize - 1 || next.y>mazesize - 1) return false;
	if (maze[next.x][next.y] != 0) return false;
	return true;
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