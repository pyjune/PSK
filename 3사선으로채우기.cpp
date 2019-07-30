#include <stdio.h>

int A[100][100];

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, R, C;
		scanf("%d %d %d", &N, &R, &C);
		int k = 1;
		for (int m = 1; m < N; m++)
		{
			for (int row = 0; row < N - m; row++)
			{
				int col = row + m;
				A[row][col] = k++;
			}
		}
		printf("#%d %d\n", tc, A[R][C]);
	}
}
