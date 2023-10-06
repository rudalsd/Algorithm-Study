#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#define ll long long
#define M 1000000000000000000

using namespace std;

int n;
ll dp[1001][320];

ll dfs(int i, int j)
{
	if (dp[i][j] != -1) return dp[i][j];
	if (i - M_PI * j >= 0 && i - M_PI * j <= M_PI) return 1;
	return dp[i][j] = (dfs(i - 1, j) % M + dfs(i, j + 1) % M) % M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 319; j++) {
			dp[i][j] = -1;
		}
	}

	cout << dfs(n, 0);
}
