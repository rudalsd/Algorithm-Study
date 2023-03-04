#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<pair<int, int>> list[1001];
int visited[1001];
int a, b;

void dfs(int num, int dist)
{
	if (num == b) {
		printf("%d\n", dist);
		return;
	}
	for (auto& next : list[num]) {
		if (visited[next.first] != 1) {
			visited[next.first] = 1;
			dfs(next.first, dist + next.second);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	for (int i = 0; i < M; i++) {
		fill(visited, visited + N + 1, 0);
		scanf("%d %d", &a, &b);
		visited[a] = 1;
		dfs(a, 0);
	}
}