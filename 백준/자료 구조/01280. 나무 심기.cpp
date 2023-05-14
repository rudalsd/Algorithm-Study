#include<iostream>
#define ll long long
#define M 1000000007

using namespace std;

int N;
ll segTree[400002];
ll segTree2[400002];
ll ans = 1;

void updateTree(ll idx)
{
	ll temp = idx - 200001;

	while (idx != 0) {
		segTree[idx] += temp;
		segTree2[idx]++;
		idx >>= 1;
	}
}

pair<ll,ll> getTree(int l, int r)
{
	ll ret = 0;
	ll ret2 = 0;

	while (l <= r) {
		if (l & 1) {
			ret += segTree[l];
			ret2 += segTree2[l];
			l++;
		}
		if (~r & 1) {
			ret += segTree[r];
			ret2 += segTree2[r];
			r--;
		}

		l >>= 1;
		r >>= 1;
	}

	return { ret, ret2 };
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		ll idx;
		scanf("%lld", &idx);
		pair<ll, ll> temp;
		pair<ll, ll> temp2;

		updateTree(idx + 200001);

		if (i != 0) {
			if (idx == 0) {
				temp = getTree(200001 + idx + 1, 400001);
				ans = ((ans % M) * ((temp.first - idx * temp.second) % M)) % M;
			}
			else if (idx == 200000) {
				temp = getTree(200001, 200001 + idx - 1);
				ans = ((ans % M) * ((idx * temp.second - temp.first) % M)) % M;
			}
			else {
				temp = getTree(200001, 200001 + idx - 1);
				temp2 = getTree(200001 + idx + 1, 400001);
				ans = ((ans % M) * ((temp2.first - idx * temp2.second + idx * temp.second - temp.first) % M)) % M;
			}
		}
	}

	printf("%lld", ans);
}