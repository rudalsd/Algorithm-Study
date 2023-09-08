#include<iostream>

using namespace std;

int n;
int arr[100000];
int dp[100000][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0][0] = arr[0];

	int ans = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
		ans = max(max(ans, dp[i][0]), dp[i][1]);
	}

	cout << ans;
}
