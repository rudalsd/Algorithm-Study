#include<iostream>

using namespace std;

int M, N;
int arr[1001][1001];
int dp[1001][1001];
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0) {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i-1][j-1])) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;
}
