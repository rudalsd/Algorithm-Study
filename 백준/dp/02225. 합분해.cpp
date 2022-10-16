#include<iostream>
#define M 1000000000

using namespace std;

int N, K;
int dp[201][201];

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= N; k++) {
				if (j + k <= N) {
					dp[i][j + k] += dp[i - 1][j];
					dp[i][j + k] %= M;
				}
			}
		}
	}

	printf("%d", dp[K][N]);
}