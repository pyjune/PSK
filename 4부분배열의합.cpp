#include <stdio.h>

int A[100][100];

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int maxV = 0;
		int N, n, m;
		scanf("%d %d %d", &N, &n, &m);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &A[i][j]);
		for (int i = 0; i <= N - n; i++)
		{
			for (int j = 0; j <= N - m; j++)
			{
				int s = 0;
				/*for (int r = 0; r < n; r++)
					for (int c = 0; c < m; c++)
						s += A[i + r][j + c];*/
				for (int r = i; r < i+n; r++)
					for (int c = j; c < j+m; c++)
						s += A[r][c];
				if (maxV < s)
					maxV = s;

			}
		}
		printf("#%d %d\n", tc, maxV);
	}
}
