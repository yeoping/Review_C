#define _CRT_SECURE_NO_WARNINGS
#include "pos.h"
#include "stackADT.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX 100			/* maze size */
#define PATH 0			/* �� */
#define WALL 1			/* �� */
#define VISITED 2		/* �湮 ǥ�� */
#define BACKTRACKED 3	/* �湮 �� �ǵ��ƿ� ��ġ*/

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
			if (movable(cur, dir))		//��� �������ε� ������ ����
			{
				push(s, cur);
				cur = move_to(cur, dir);
				forward = true;
				break;
			}
		}
		if (!forward)
		{
			maze[cur.x][cur.y] = BACKTRACKED;	//�ǵ��ư� ǥ��
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
	if (next.x<0 || next.y<0 || next.x>mazesize - 1 || next.y>mazesize - 1) return false;	//�̷� ���� ��ǥ
	if (maze[next.x][next.y] != 0) return false;	//�� �� ���� ��
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
1. ��, ��, �� ,�� ������� ���� Ž�� �� �̵� �� �� ������ �ϴ� �̵�, ���ÿ� Ǫ��
2. ���̻� �̵��� �� ������ ���ÿ��� pop �Ͽ� �� ��ġ���� �ٽ� �˻�(������ ����ִٸ� ���� ã�� �� ����)

*/

