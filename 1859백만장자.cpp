#include <stdio.h>

int arr[1000000];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		long long s = 0;
		int maxV;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		maxV = arr[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (arr[i] < maxV)
				s += maxV - arr[i];
			else
				maxV = arr[i];
		}
		printf("#%d %lld\n", tc, s);
	}
}
