#include<iostream>
#include<vector>

using namespace std;

int N, M;
int H[5001];
int dp[5001];
vector<int> list[5001];

int dfs(int cur)
{
	if (dp[cur] != -1) return dp[cur];
	int& ret = dp[cur];
	ret = 1;

	for (auto& next : list[cur]) {
		if (H[cur] < H[next]) {
			ret = max(ret, dfs(next) + 1);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> H[i];
		dp[i] = -1;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		list[u].push_back(v);
		list[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		cout << dfs(i) << '\n';
	}
}