#include <stdio.h>


int box[1000][1000];
int visited[1000][1000];
int q[2000000];
int front = -1;
int rear = -1;

int bfs(int n, int m);

int main(void)
{
	int M, N;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &box[i][j]);
	int r = bfs(N, M);

	printf("%d\n", r);
}

int bfs(int n, int m)
{
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };
	int maxV = 0;
	// 익은 토마토가 들어있는 칸을 enq()하고 1일차로 기록
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 1)
			{
				q[++rear] = i;
				q[++rear] = j;
				visited[i][j] = 1;
			}
		}
	while (front != rear)
	{
		int r = q[++front]; // deq()
		int c = q[++front];
		if (visited[r][c] > maxV) // 익는데 더 오래 걸렸으면
			maxV = visited[r][c];
		for (int k = 0; k < 4; k++)
		{
			int nr = r + dr[k]; // 익은 토마토의 주변
			int nc = c + dc[k];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (box[nr][nc] == 0 && visited[nr][nc] == 0)
				{
					q[++rear] = nr;
					q[++rear] = nc;
					box[nr][nc] = 1; // 익은 토마토 표시
					visited[nr][nc] = visited[r][c] + 1; // 몇일차에 익었는지 표시
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (box[i][j] == 0) // 끝까지 안익은 토마토 찾기
				return -1;

	return maxV - 1; // 마지막으로 익은 maxV일차에서 1일차를 뺌
}
