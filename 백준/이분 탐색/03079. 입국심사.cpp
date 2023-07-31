#include<iostream>
#define ll long long

using namespace std;
int arr[100000];
int N, M;

bool check(ll mid)
{
	ll num = 0;

	for (int i = 0; i < N; i++) {
		num += mid / arr[i];

		if (num >= M) {
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int Min = 1111111111;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		Min = min(Min, arr[i]);
	}

	ll s = 0;
	ll e = 1LL * Min * M + 1;
	ll ans = 0;

	while (s < e) {
		ll m = (s + e) / 2;

		if (check(m)) {
			e = m;
			ans = e;
		}
		else {
			s = m + 1;
		}
	}

	cout << ans;
}
