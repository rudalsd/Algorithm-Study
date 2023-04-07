#include<iostream>
#define ll long long
#include<vector>

using namespace std;

ll G;
vector<ll> ans;

int main()
{
	scanf("%lld", &G);

	ll s = 1;
	ll e = 2;

	while (e < G) {
		ll cur = e * e;
		ll before = s * s;

		if (cur - before == G) {
			ans.push_back(e);
			e++;
		}
		else if (cur - before > G) {
			s++;
		}
		else {
			e++;
		}
	}

	if (ans.size() == 0) {
		printf("-1");
		return 0;
	}

	for (auto& next : ans) {
		printf("%lld\n", next);
	}
}