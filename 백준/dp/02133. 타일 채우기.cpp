#include<iostream>

using namespace std;

int N;
int dp[31];

int main()
{
	dp[0] = 1;
	dp[2] = 3;

	scanf("%d", &N);

	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * 4 - dp[i - 4];
	}

	printf("%d", dp[N]);
}