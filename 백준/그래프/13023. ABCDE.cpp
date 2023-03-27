#include<iostream>
#include<vector>

using namespace std;

int N, M;
int ans;
vector<int> list[2000];
int visited[2000];

void dfs(int cur, int cnt)
{
	ans = max(ans, cnt);
	if (ans > 4) return;
	cnt++;

	for (auto& next : list[cur]) {
		if (visited[next] != 1) {
			visited[next] = 1;
			dfs(next, cnt);
			visited[next] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		fill(visited, visited + N, 0);
		visited[i] = 1;
		dfs(i, 1);
	}

	if (ans > 4) {
		printf("1");
	}
	else{
		printf("0");
	}
}