#include <stdio.h>


int maze[100][100];

int dfs(int r, int c);
int bfs(int r, int c);

int main(void)
{
	int T, N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int rs, cs;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2)
				{
					rs = i;
					cs = j;
				}
			}
		printf("#%d %d\n", tc, dfs(rs, cs));
		//printf("#%d %d\n", tc, bfs(rs, cs));
	}
}

int dfs(int r, int c)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (maze[r][c] == 3)
		return 1;
	else
	{
		maze[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (maze[nr][nc] != 1)
			{
				if (dfs(nr, nc) == 1)
					return 1;
			}
		}
		return 0;
	}
}

int bfs(int i, int j)
{
	int di[] = { 0, 1, 0, -1 };
	int dj[] = { 1, 0, -1, 0 };
	int q[20000];
	int v[100][100] = { 0, };
	int f = -1;
	int r = -1;
	q[++r] = i;
	q[++r] = j;
	v[i][j] = 1;
	while(f != r)
	{
		i = q[++f];
		j = q[++f];
		if (maze[i][j] == 3)
			return 1;
		for (int k = 0; k < 4; k++)
		{
			int ni = i + di[k];
			int nj = j + dj[k];
			if (maze[ni][nj] != 1 && v[ni][nj] == 0)
			{
				q[++r] = ni;
				q[++r] = nj;
				v[ni][nj] = v[i][j] + 1;
			}
		}
	}
	return 0;
}
