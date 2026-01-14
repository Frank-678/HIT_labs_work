#include <stdio.h>

int rsame(int N, int M, char arr[][M]);
int csame(int N, int M, char arr[][M]);

int main(void)
{
	int N, M;
	char arr[N][M];
	scanf("%i %i", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", arr[i] + j);
		}
	}
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (rsame(N, M, arr) == i)
			{
				arr[i][j] = '0';
				printf("R %i", i);
			}	
		}
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (csame(N, M, arr) == j)
			{
				arr[i][j] = '0';
				printf("C %i", j);
			}	
		}
	}		
}

int rsame(int N, int M, char arr[][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'P' || arr[i][j] == 'R')
			{
				return i;
			}	
		}
	}
	return -1;
}

int csame(int N, int M, char arr[][M])
{
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i][j] == 'P' || arr[i][j] == 'R')
			{
				return j;
			}	
		}
	}
	return -1;
}
