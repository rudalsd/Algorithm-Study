#include<iostream>
#define ll long long

using namespace std;

int N;
int cnt[20];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		int bi = 0;

		while (num != 0) {
			cnt[bi] += (num & 1);
			num >>= 1;
			bi++;
		}
	}

	ll ans = 0;

	for (int i = 0; i < 20; i++) {
		ans += (1LL << i) * 1LL * cnt[i] * (1LL * N - cnt[i]);
	}

	printf("%lld", ans);
}
