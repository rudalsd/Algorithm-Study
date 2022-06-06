#include <iostream>

using namespace std;

struct stuff {
	int W;
	int V;
};

int N, K;
stuff arr[101];
int dp[101][100001];

int main()
{
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].W >> arr[i].V;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= arr[i].W) {
				dp[i][j] = max(dp[i - 1][j - arr[i].W] + arr[i].V, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}
