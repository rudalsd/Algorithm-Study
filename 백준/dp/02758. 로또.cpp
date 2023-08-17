#include<iostream>
#include<cmath>
#define ll long long

using namespace std;

int T, n, m;
ll dp[11][2001];

ll dfs(int n, int m)
{
	if (n == 1) {
		return 1;
	}

	ll& ret = dp[n][m];

	if (ret != -1) {
		return ret;
	}

	ret = 0;

	for (int i = m / 2; i >= 1; i--) {
		ret += dfs(n - 1, i);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 2000; j++) {
			dp[i][j] = -1;
		}
	}

	for (int t = 0; t < T; t++) {
		cin >> n >> m;

		ll ans = 0;

		for (int i = m; i >= 1; i--) {
			ans += dfs(n, i);
		}

		cout << ans << '\n';
	}
}
