#include <stdio.h>


int maze[100][100];

void dfs(int r, int c, int e);
int bfs(int r, int c);
int minV;

int main(void)
{
	int T, N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		minV = 10000;
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
		dfs(rs, cs, 0);
		minV = minV == 10000 ? 0 : minV - 1;
		//printf("#%d %d\n", tc, minV);
		printf("#%d %d\n", tc, bfs(rs, cs));
	}
}

void dfs(int r, int c, int e)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	if (maze[r][c] == 3)
	{
		if (e < minV)
			minV = e;
	}
	else
	{
		maze[r][c] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (maze[nr][nc] != 1)
			{
				dfs(nr, nc, e + 1);
			}
		}
		maze[r][c] = 0;
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
			return v[i][j]-2;
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
