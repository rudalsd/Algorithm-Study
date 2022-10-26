#include<iostream>

using namespace std;

int N, M;
int arr[101];
int dp[101][51];	//i번째 숫자까지 j개의 구간으로 나누었을 때 최댓값
int sum[101];

int DP(int n, int m)
{
	if (n < m * 2 - 1) return -987654321;
	if (m == 0) return 0;
	if (dp[n][m] != -987654321) return dp[n][m];

	dp[n][m] = DP(n - 1, m);

	for (int i = n; i >= 1; i--) {
		int temp = DP(i - 2, m - 1);
		dp[n][m] = max(dp[n][m], temp + sum[n] - sum[i - 1]);
	}

	return dp[n][m];
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= (N + 1) / 2; j++) {
			dp[i][j] = -987654321;
		}
	}

	printf("%d", DP(N, M));
}