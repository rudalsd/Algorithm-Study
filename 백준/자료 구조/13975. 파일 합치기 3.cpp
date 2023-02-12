#include<iostream>
#include<queue>
#define ll long long

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int K;
		scanf("%d", &K);

		priority_queue<ll, vector<ll>, greater<ll>> pq;

		ll ans = 0;

		for (int i = 0; i < K; i++) {
			ll num;
			scanf("%lld", &num);

			pq.push(num);
		}

		while (1) {
			const ll a = pq.top();
			pq.pop();
			const ll b = pq.top();
			pq.pop();

			ans += a + b;

			if (pq.empty()) break;

			pq.push(a + b);
		}

		printf("%lld\n", ans);
	}
}