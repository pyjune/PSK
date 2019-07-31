// 5개 중 3개를 사용해 순열 만들기

#include <stdio.h>

int A[] = { 1,2,3,4,5 };
int p[5];
int used[5];

void f(int n, int k, int m); //  

int main(void)
{
	f(0, 3, 5);
}

void f(int n, int k, int m)
{
	if (n == k) // k개의 자리가 채워진 경우
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = A[i];
				f(n + 1, k, m);
				used[i] = 0;
			}
		}
	}
}
