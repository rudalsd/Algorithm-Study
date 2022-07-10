#include<iostream>

#define ll long long
#define MOD 1000000007

using namespace std;

ll fac[4000001];

int M, N, K;

ll pow(ll num, int p)		//분할 정복을 이용한 거듭제곱
{
	if (p == 0) return 1;
	if (p == 1) return num;

	if (p % 2 == 0) {
		ll temp = pow(num, p / 2);
		temp %= MOD;
		return (temp * temp) % MOD;
	}
	else {
		ll temp = pow(num, p - 1);
		temp %= MOD;
		return (num * temp) % MOD;
	}
}

int main()
{
	fac[0] = 1;

	for (int i = 1; i <= 4000000; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &N, &K);		//페르마의 소정리
		ll ans = (fac[N] * pow((fac[N - K] * fac[K]) % MOD, MOD - 2)) % MOD;
		printf("%lld\n", ans);
	}
}