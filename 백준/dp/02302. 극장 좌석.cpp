#include<iostream>

using namespace std;

int N, M;
int dp[41];
int ans = 1;

int main()
{
	scanf("%d %d", &N, &M);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int before = 0;

	if (M == 0) {
		printf("%d", dp[N]);
		return 0;
	}

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		ans *= dp[num - before - 1];
		before = num;
	}

	ans *= dp[N - before];

	printf("%d", ans);
}