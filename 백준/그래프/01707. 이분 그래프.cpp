#include<iostream>
#include<vector>

using namespace std;

int K, V, E;
vector<int> list[20001];
int visited[20001];

bool dfs(int cur, int stat)
{
	for (auto& next : list[cur]) {
		if (visited[next] == 0) {
			visited[next] = -stat;
			dfs(next, -stat);
		}
		else if (visited[next] == stat) {
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	while (K--) {
		cin >> V >> E;
		bool flag = true;

		for (int i = 1; i <= V; i++) {
			list[i].clear();
			visited[i] = 0;
		}

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			list[u].push_back(v);
			list[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) visited[i] = 1;
			if (!dfs(i, visited[i])) {
				printf("NO\n");
				flag = false;
				break;
			}
		}

		if (flag) {
			printf("YES\n");
		}
	}
}
