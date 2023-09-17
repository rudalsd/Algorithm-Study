#include<iostream>
#include<vector>

using namespace std;

int N, R;
int a, b, d;
vector<pair<int, int>> list[200001];
int visited[200001];
int all;
int gidung = 987654321;

void dfs(int node, int dist)
{
	int cnt = 0;
	all = max(all, dist);
	for (auto& next : list[node]) {
		if (visited[next.first] == 0) {
			cnt++;
			visited[next.first] = 1;
			dfs(next.first, dist + next.second);
			visited[next.first] = 0;
		}
	}

	if (cnt >= 2) {
		gidung = min(gidung, dist);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R;

	for (int i = 0; i < N - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		list[a].push_back({ b,d });
		list[b].push_back({ a,d });
	}

	visited[R] = 1;
	dfs(R, 0);

	if (gidung == 987654321) {
		gidung = all;
	}

	cout << gidung << ' ' << all - gidung;
}