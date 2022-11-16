#include<iostream>
#define ll long long

using namespace std;

pair<ll, ll> arr[4];

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll ret = (a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second);

	if (ret > 0) return 1;
	else return -1;
}

int main()
{
	for (int i = 0; i < 4; i++) {
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
	}

	if (ccw(arr[0], arr[1], arr[2]) * ccw(arr[0], arr[1], arr[3]) < 0 && ccw(arr[2], arr[3], arr[0]) * ccw(arr[2], arr[3], arr[1]) < 0) {
		printf("%d", 1);
	}
	else {
		printf("%d", 0);
	}
}