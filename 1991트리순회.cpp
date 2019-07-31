#include <stdio.h>

int ch1[27]; // 1~5번 노드인 경우
int ch2[27];


void dlr2(int n);
void ldr2(int n);
void lrd2(int n);

int main(void)
{
	int N;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) // 간선 개수 만큼 반복
	{
		char p, c1, c2;
		scanf(" %c %c %c", &p, &c1, &c2);
		if (c1!='.') // 1번 자식노드가 아직 없는 경우
			ch1[p-'A'+1] = c1 - 'A' + 1;
		if(c2 != '.')
			ch2[p-'A'+1] = c2 - 'A' + 1;

	}
	dlr2(1);
	printf("\n");
	ldr2(1);
	printf("\n");
	lrd2(1);
	printf("\n");
	
}



void dlr2(int n) // 전위순회
{
	if (n != 0)
	{
		printf("%c", n - 1 + 'A');
		dlr2(ch1[n]);
		dlr2(ch2[n]);
	}
}

void ldr2(int n) // 중위순회
{
	if (n != 0)
	{
		ldr2(ch1[n]);
		printf("%c", n - 1 + 'A');
		ldr2(ch2[n]);
	}
}

void lrd2(int n) // 후위순회
{
	if (n != 0)
	{
		lrd2(ch1[n]);
		lrd2(ch2[n]);
		printf("%c", n - 1 + 'A');
	}
}
