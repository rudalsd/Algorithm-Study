#include<iostream>
#define ll long long

using namespace std;

int N;
ll dp[1001];
ll n[3];
ll ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> dp[1];
	n[2] = n[1] = 0;

	for (int i = 1; i < N; i++) {
		int t;
		cin >> t;
		ll tmp = -5005000001;
		for (int j = i; j >= 1; j--) {
			tmp = max(tmp, dp[j]);
			dp[j + 1] = dp[j] + 1LL * t * (j + 1);
		}
		dp[0] = max(n[1], n[2]);
		dp[1] = dp[0] + t;
		n[2] = n[1];
		n[1] = tmp;
	}
	
	ans = max(n[1], n[2]);

	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}

	if (ans < 0) cout << 0;
	else cout << ans;
}