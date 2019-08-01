#include <stdio.h>

int num[10];
int arr[10][10];
int visited[10][10];

int solution(int n, int m);
int find(int i, int j, int n, int m, int idx);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &num[i]);
		scanf("%d", &M);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &arr[i][j]);
		printf("#%d %d\n", tc, solution(N, M));
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				visited[i][j] = 0;
	}
}

int find(int i, int j, int n, int m, int idx)
{
	int di[] = { 0, 1, 0, -1 };
	int dj[] = { 1, 0, -1, 0 };

	if (idx == n)
	{
		return 1;
	}
	else if (arr[i][j] != num[idx])
	{
		return 0;
	}
	else if(visited[i][j] == 0)
	{
		visited[i][j] = 1;
		for (int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if (ni >= 0 && ni < m && nj >= 0 && nj < m)
				if (find(ni, nj, n, m, idx + 1) == 1)
					return 1;
		}
		visited[i][j] = 0;
		//return 0;
	}
	return 0;
}

int solution(int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == num[0])
				if (find(i, j, n, m, 0) == 1)
					return 1;
		}
	}
	return 0;
}
