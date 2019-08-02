#include <stdio.h>

int arr[1000];
int d[1000];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int maxV = 1;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			d[i] = 1;
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[j]<arr[i] && (d[j] + 1)>d[i])
				{
					d[i] = d[j] + 1;
					maxV = maxV < d[i] ? d[i] : maxV;
				}
			}
		}
		printf("#%d %d\n", tc, maxV);
	}
}
