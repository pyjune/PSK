#include <stdio.h>

int arr[101][101];
int d[101][101];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				scanf("%d", &arr[i][j]);

		for (int i = 0; i <= N; i++)
			d[i][0] = 1000000;
		for (int j = 0; j <= M; j++)
			d[0][j] = 1000000;
		d[1][0] = 0;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				d[i][j] = (d[i - 1][j] < d[i][j - 1]) ? (d[i - 1][j] + arr[i][j]) : (d[i][j - 1] + arr[i][j]);
			}
		printf("#%d %d\n", tc, d[N][M]);
	}
}
