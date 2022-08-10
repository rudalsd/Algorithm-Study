#include<iostream>

using namespace std;

int n;
int arr[500][500];
int dp[500][500];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}

	int ans = dp[n - 1][0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		ans = max(ans, dp[n - 1][i]);
	}

	printf("%d", ans);
}