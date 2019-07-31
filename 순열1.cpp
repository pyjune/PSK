// 5개의 숫자를 1번씩 사용해 5자리 수 만들기

#include <stdio.h>

int A[] = { 1,2,3,4,5 };
int p[5];
int used[5];

void f(int n, int k); //  

int main(void)
{
	f(0, 5);
}

void f(int n, int k)
{
	if (n == k) // k개의 자리가 채워진 경우
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = A[i];
				f(n + 1, k);
				used[i] = 0;
			}
		}
	}
}
