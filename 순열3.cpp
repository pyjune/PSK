// n번 인덱스자리부터 오른쪽 숫자와 자리를 바꿔보는 

#include <stdio.h>

int A[] = { 1,2,3 };

void f(int n, int k); //  

int main(void)
{
	f(0, 3);
}

void f(int n, int k)
{
	if (n == k) // k개의 자리가 채워진 경우
	{
		for (int i = 0; i < k; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for (int i = n; i < k; i++)
		{
			int tmp = A[n];
			A[n] = A[i];
			A[i] = tmp;
			f(n + 1, k);
			tmp = A[n];
			A[n] = A[i];
			A[i] = tmp;
		}
	}
}
