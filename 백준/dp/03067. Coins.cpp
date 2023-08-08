#include<iostream>

using namespace std;

int T;
int coin[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N;
		int dp[21][10001] = { 0 };
		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
			dp[i][0] = 1;
		}

		cin >> M;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (j < coin[i]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i][j - coin[i]] + dp[i - 1][j];
			}
		}

		cout << dp[N][M] << '\n';
	}
}