#include<iostream>
#define ll long long
#define M 1000000007

using namespace std;

int N;
ll dp[2][1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp[0][0] = 1;
	dp[0][1] = 2;
	dp[0][2] = 7;

	for (int i = 3; i <= N; i++) {
		dp[1][i] = (dp[1][i - 1] % M + dp[0][i - 3] % M) % M;
		dp[0][i] = (3 * dp[0][i - 2] % M + 2 * dp[0][i - 1] % M + 2 * dp[1][i] % M) % M;
	}

	cout << dp[0][N];
}
