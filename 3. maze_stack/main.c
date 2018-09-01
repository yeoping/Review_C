#define _CRT_SECURE_NO_WARNINGS
#include "pos.h"
#include "stackADT.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX 100			/* maze size */
#define PATH 0			/* 길 */
#define WALL 1			/* 벽 */
#define VISITED 2		/* 방문 표시 */
#define BACKTRACKED 3	/* 방문 후 되돌아온 위치*/

//func
void read_maze(char *filename);
void print_maze();
bool movable(Position cur, int dir);

// // // // //

int maze[MAX][MAX];
int mazesize;

int main()
{
	read_maze("maze.txt");
	printf("# original \n");
	print_maze();
	
	Stack s = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;
	while (1)
	{
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == mazesize - 1 && cur.y == mazesize - 1)
		{
			printf("Found the path\n");
			break;
		}
		bool forward = false;
		for (int dir = 0; dir < 4; dir++)
		{
			if (movable(cur, dir))		//어디 방향으로든 전진에 성공
			{
				push(s, cur);
				cur = move_to(cur, dir);
				forward = true;
				break;
			}
		}
		if (!forward)
		{
			maze[cur.x][cur.y] = BACKTRACKED;	//되돌아감 표시
			if (!is_empty(s))
			{
				printf("No path exists.\n");
				break;
			}
			cur = pop(s);
		}
	}

	print_maze();
}


bool movable(Position cur, int dir)
{
	Position next = move_to(cur, dir);
	if (next.x<0 || next.y<0 || next.x>mazesize - 1 || next.y>mazesize - 1) return false;	//미로 밖의 좌표
	if (maze[next.x][next.y] != 0) return false;	//갈 수 없는 길
	return true;
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



/*
DFS(Deep Frist Search) method
1. 북, 동, 남 ,서 순서대로 방향 탐색 후 이동 할 수 있으면 일단 이동, 스택에 푸쉬
2. 더이상 이동할 수 없으면 스택에서 pop 하여 전 위치에서 다시 검색(스택이 비어있다면 길을 찾을 수 없음)

*/

