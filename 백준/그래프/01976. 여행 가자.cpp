#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[201][201];
int route[1000];
int visited[201];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &route[i]);
	}

	queue<int> q;
	q.push(route[0]);
	visited[route[0]] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (visited[i] != 1 && arr[cur][i] == 1) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (visited[route[i]] == 0) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}