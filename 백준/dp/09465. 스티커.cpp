#include<iostream>

using namespace std;

int arr[2][100002];
int dp[2][100002];

int main()
{
	int t;
	scanf("%d", &t);

	for (int T = 0; T < t; T++) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 2; j <= n + 1; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 2; i <= n + 1; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		int ans = 0;

		ans = max(dp[0][n + 1], dp[1][n + 1]);

		printf("%d\n", ans);
	}
}