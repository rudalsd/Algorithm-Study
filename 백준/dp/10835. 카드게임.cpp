#include<iostream>

using namespace std;

int N;
int dp[2000][2000];
int l[2000];
int r[2000];
int ans;

int dfs(int left, int right)
{
	if (left == N || right == N) return 0;
	if (dp[left][right] != -1) return dp[left][right];

	int& ret = dp[left][right];
	ret = 0;
	
	ret = max(dfs(left + 1, right), dfs(left + 1, right + 1));

	if (l[left] > r[right]) {
		ret = max(ret, dfs(left, right + 1) + r[right]);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> l[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> r[i];
	}

	cout << dfs(0, 0);
}