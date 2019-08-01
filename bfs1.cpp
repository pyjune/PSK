#include <stdio.h>

//5 6
//1 2 1 3 3 2 2 5 5 4 3 4

int adj[6][6];
int visited[6];

void bfs(int n, int k);

int main(void)
{
	int V, E;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 무방향인 경우
	}
	bfs(1, 5);
}

void bfs(int n, int k)
{
	int queue[6];
	int front = -1;
	int rear = -1;
	queue[++rear] = n; // enqueue(n)
	visited[n] = 1;
	while (front != rear) // 큐가 비어있지 않으면 반복
	{
		n = queue[++front]; // dequeue()
		printf("%d ", n);
		for (int i = 1; i <= k; i++)
		{
			if (adj[n][i] != 0 && visited[i] == 0)
			{
				queue[++rear] = i;
				visited[i] = visited[n] + 1;
			}
		}
	}
}
