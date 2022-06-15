#include <iostream>

using namespace std;

int N, K;
int dp[200001];

void tel(int num)		//순간이동
{
	int cur = num;
	while (1) {
		num *= 2;
		if (num > 200001) {
			break;
		}
		if (dp[num] > dp[cur]) {
			dp[num] = dp[cur];
		}
	}
}

int main()
{
	cin >> N >> K;

	for (int i = 0; i < 200001; i++) {
		dp[i] = 987654321;
	}

	for (int i = 0; i < 200001; i++) {
		if (i <= N) {
			dp[i] = N - i;
		}
		else {
			if (i % 2 == 0) {
				dp[i] = min(min(dp[i - 1] + 1, dp[i + 1] + 1), dp[i / 2]);
			}
			else {
				dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
			}
		}
		if (i > 0) {
			tel(i);
		}
	}

	cout << dp[K];
}