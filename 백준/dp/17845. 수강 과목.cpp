#include<iostream>

using namespace std;

int N, K;
int dp[1001][10001];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; i++) {
		int I, T;
		scanf("%d %d", &I, &T);

		for (int j = 1; j <= N; j++) {
			if (T > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T] + I);
			}
		}
	}

	printf("%d", dp[K][N]);
}