#include<iostream>

using namespace std;

int N, K;
int arr[10][10];
int dist[10][10];
int visited[10];
int ans = 987654321;
int hap;

void dfs(int cur, int level)
{
	if (level == N - 1) {
		ans = min(ans, hap);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] != 1) {
			visited[i] = 1;
			hap += dist[cur][i];
			dfs(i, level + 1);
			hap -= dist[cur][i];
			visited[i] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			dist[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	visited[K] = 1;

	dfs(K, 0);

	printf("%d", ans);
}