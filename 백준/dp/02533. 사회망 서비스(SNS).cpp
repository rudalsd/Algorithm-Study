#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> list[1000001];
vector<int> tree[1000001];
int dp[1000001][2];
int visited[1000001];
int N;
int ans = 987654321;

int dfs(int node, int state)		//상태에 따라 최솟값을 저장
{
	if (dp[node][state] != -1) return dp[node][state];
	dp[node][state] = state;

	if (state == 0) {
		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			dp[node][state] += dfs(next, 1);
		}
	}
	else {
		for (int i = 0; i < tree[node].size(); i++) {
			int next = tree[node][i];
			dp[node][state] += min(dfs(next, 0), dfs(next, 1));
		}
	}

	return dp[node][state];
}

void makeTree(int node)		//그래프를 트리로 재설정
{
	visited[node] = 1;

	for (int i = 0; i < list[node].size(); i++) {
		int next = list[node][i];
		if (visited[next] != 1) {
			tree[node].push_back(next);
			makeTree(next);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		list[u].push_back(v);
		list[v].push_back(u);
	}

	makeTree(1);

	memset(dp, -1, sizeof(dp));

	int ans = min(dfs(1, 0), dfs(1, 1));

	cout << ans;
}