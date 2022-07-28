#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> list[100001];
int visited[100001];
int parent[100001];

void dfs(int node)
{
	if (visited[node] == 1) return;
	visited[node] = 1;

	for (auto next : list[node]) {
		if (visited[next] != 1) {
			parent[next] = node;
			dfs(next);
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
}