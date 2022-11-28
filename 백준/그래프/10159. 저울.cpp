#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[101][101];
int cnt[101];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a][b] = 2;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		int visited[101] = { 0 };

		queue<pair<int, int>> q;
		visited[i] = 1;

		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != 0) {
				q.push({ j,arr[i][j] });
				cnt[i]++;
				visited[j] = 1;
			}
		}

		while (!q.empty()) {
			const int cur = q.front().first;
			const int ineq = q.front().second;
			q.pop();

			for (int j = 1; j <= N; j++) {
				if (visited[j] != 1 && arr[cur][j] == ineq) {
					visited[j] = 1;
					q.push({ j,ineq });
					cnt[i]++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", N - cnt[i] - 1);
	}
}