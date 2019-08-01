#include <stdio.h>

//5 6
//1 2 1 3 3 2 2 5 5 4 3 4

void dfs(int n, int k);
int adj[6][6];
int visited[6];

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
		adj[n2][n1] = 1; // 무방향인 경우
	}
	dfs(1, V);
}

void dfs(int n, int k)
{
	visited[n] = 1;
	printf("%d ", n);
	for (int i = 1; i <= k; i++)
	{
		// i번 노드가 n에 인접하고, 방문하지 않은 노드면
		if (adj[n][i] != 0 && visited[i] == 0)
		{
			dfs(i, k);
		}
	}
}
