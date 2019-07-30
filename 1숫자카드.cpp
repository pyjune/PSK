#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int tc, T;
	int i;
	int N;
	int card;
	int maxIdx;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++)
	{
		int count[10] = {0,}; // 하나만 0으로 초기화하면 전체가 0.. 
		
		scanf("%d", &N);
		for(i = 0; i<N; i++)
		{
			scanf("%1d", &card);
			count[card]++; 
		}
		maxIdx = 0;
		for(i=1;i<=9;i++)
		{
			//if(count[maxIdx]<count[i]) // 같은 값 중 가장 왼쪽.. 
			if(count[maxIdx]<=count[i])	// 같은 값 중 가장 오른쪽 선택.. 
			{
				maxIdx = i;
			}
		}
		printf("#%d %d %d\n", tc, maxIdx, count[maxIdx]);
	}
		
	return 0;
}
