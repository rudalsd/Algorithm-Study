#include<iostream>
#define ll long long
#define M 1000000007

using namespace std;

ll Fac[4000001];

ll p(int n, int k)
{
	if (k == 0) return 1;
	if (k == 1) return n;

	if (k % 2 == 0) {
		ll temp = p(n, k / 2);
		temp %= M;

		return (temp * temp) % M;
	}
	else {
		ll temp = p(n, k - 1);
		temp %= M;

		return (temp * n) % M;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	Fac[0] = 1;
	Fac[1] = 1;

	for (int i = 2; i <= N; i++) {
		Fac[i] = Fac[i - 1] * i;
		Fac[i] %= M;
	}

	ll ans = Fac[N] * p((Fac[N - K] * Fac[K])%M, M - 2);
	ans %= M;

	cout << ans;
}