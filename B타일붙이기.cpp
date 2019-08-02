#include <stdio.h>

long long d[31];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
    //d[0] = 1; // 아무것도 붙이기 않는 경우 1가지
		d[1] = 1;
		d[2] = 3;
		d[3] = 6;
		for (int i = 4; i <= N; i++) // d[0]부터인 경우 int i = 3;
		{
			d[i] = d[i-1]+2*d[i-2]+d[i-3];
		}
		printf("#%d %lld\n", tc, d[N]);
	}
}
