#include<iostream>

using namespace std;

int n;
int dp[1001];

int main()
{
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
		dp[i] %= 10007;
	}

	cout << dp[n];
}