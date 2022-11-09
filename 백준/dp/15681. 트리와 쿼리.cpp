#include<iostream>
#include<vector>

using namespace std;

int N, R, Q;
vector<int> list[100001];
int dp[100001];
int visited[100001];

int dfs(int cur)
{
	if (dp[cur] != 0) return dp[cur];
	if (visited[cur] == 1) return 0;
	visited[cur] = 1;

	for (auto next : list[cur]) {
		if (visited[next] != 1) {
			dp[cur] += dfs(next);
		}
	}

	return dp[cur] += 1;
}

int main()
{
	scanf("%d %d %d", &N, &R, &Q);

	for (int i = 1; i < N; i++) {
		int U, V;
		scanf("%d %d", &U, &V);
		list[U].push_back(V);
		list[V].push_back(U);
	}

	dfs(R);

	for (int i = 0; i < Q; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}
}