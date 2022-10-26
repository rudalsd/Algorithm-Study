#include<iostream>
#define M 1000000000

using namespace std;

int N;
int dp[1000001];

int main()
{
	scanf("%d", &N);

	dp[0] = 1;

	for (int i = 0; i <= 20; i++) {
		for (int j = 1; j <= N; j++) {
			if ((j - (1 << i)) >= 0) {
				dp[j] += dp[j - (1 << i)] % M;
				dp[j] %= M;
			}
		}
	}

	printf("%d", dp[N]);
}