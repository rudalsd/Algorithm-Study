#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> list[2001];
int visited[2001];
int work[1001];
int cnt;

bool dfs(int cur)
{
	if (visited[cur] == cnt) return false;
	visited[cur] = cnt;

	for (int& next : list[cur]) {
		if (!work[next] || dfs(work[next])) {
			work[next] = cur;
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
			int m;
			scanf("%d", &m);

			list[i * 2].push_back(m);
			list[i * 2 - 1].push_back(m);
		}
	}

	int ans = 0;

	for (int i = 1; i <= N * 2; i++) {
		cnt++;
		if(dfs(i)) ans++;
	}

	printf("%d", ans);
}
