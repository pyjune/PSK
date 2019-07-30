#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//3
//5 2 3 1 1
//10 2 1 3 2 2 5 4 2 1
//10 1 1 2 1 2 2 1 2 1

int bat[11]; // 최대 10번 정류장인 경우

void f(int n, int k, int c, int e);
int minV;

int main(void)
{
	int T;
	int K;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &K);
		minV = K; // 0x7fffffff
		for (int i = 1; i < K; i++) // 1번부터 k-1번 정류장에 대해
		{
			scanf("%d", &bat[i]);
		}

		f(2, K, 0, bat[1] - 1);
		printf("#%d %d\n", tc, minV);
	}
	return 0;
}

void f(int n, int k, int c, int e)
{
	if (n == k) // 종점인 경우
	{
		if (minV > c)
			minV = c;
	}
	else // 종점이 아닌 경우
	{
		// 통과
		if (e > 0)
			f(n + 1, k, c, e - 1);
		// 교체
		f(n + 1, k, c + 1, bat[n] - 1);

	}
}
