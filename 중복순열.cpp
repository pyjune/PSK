#include <stdio.h>

int A[3];
int B[] = { 1,2,3,4,5 };

void f(int n, int k, int m); // k중복순열의 길이, m 사용할 숫자 개수 

int main(void)
{
	f(0, 3, 5); // 5개의 숫자를 중복 사용해 3자리 수 만들기
}

void f(int n, int k, int m)
{
	if (n == k) // k개의 자리가 채워진 경우
	{
		for (int i = 0; i < k; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			A[n] = B[i];
			f(n + 1, k, m);
		}
	}
}
