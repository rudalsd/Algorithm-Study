#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> list[1001];
int visited[1001];
int m[1001];

bool dfs(int cur)
{
	if (visited[cur]) return false;
	visited[cur] = 1;

	for (int& next : list[cur]) {
		if (!m[next] || dfs(m[next])) {
			m[next] = cur;
			return true;
		}
	}

	return false;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			list[i].push_back(a);
		}
	}

	int ret = 0;

	for (int i = 1; i <= N; i++) {
		fill(visited, visited + N + 1, 0);
		if (dfs(i)) ret++;
	}

	printf("%d", ret);
}