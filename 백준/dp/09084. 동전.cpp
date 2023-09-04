#include<iostream>

using namespace std;

int T, N, M;
int arr[21];
int dp[21][10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			dp[i][0] = 1;
			for (int j = 1; j <= M; j++) {
				dp[i][j] = 0;
			}
		}

		cin >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (j < arr[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i]];
				}
			}
		}

		cout << dp[N][M] << '\n';
	}
}
