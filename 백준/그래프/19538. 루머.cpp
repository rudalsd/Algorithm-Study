#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
vector<int> list[200001];
int visited[200001];
int ans[200001];
int cnt[200001];

int main()
{
	queue<pair<int, int>> q;
	scanf("%d", &N);

	memset(ans, -1, 4 * (N + 1));

	int n;

	for (int i = 1; i <= N; i++) {
		while (1) {
			scanf("%d", &n);
			if (n == 0) break;
			list[i].push_back(n);
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		q.push({ n, 0 });
		ans[n] = 0;
		visited[n] = 1;
	}

	while (!q.empty()) {
		const int cur = q.front().first;
		const int min = q.front().second;
		q.pop();

		for (auto next : list[cur]) {
			if (visited[next] != 1) {
				cnt[next]++;

				if (cnt[next] >= (float)list[next].size() / 2.0f) {
					visited[next] = 1;
					ans[next] = min + 1;
					q.push({ next, min + 1 });
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", ans[i]);
	}
}