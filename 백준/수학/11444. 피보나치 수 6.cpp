#include<iostream>
#include<unordered_map>

#define ll long long

using namespace std;

ll n;
unordered_map<ll, ll> m;

ll conquer(ll num)
{
	if (num == 1) return 1;
	if (num == 0) return 0;
	if (m[num] != 0) return m[num];
	if (num % 2 == 0) {		//도가뉴의 항등식
		ll temp = num / 2;
		m[num] = conquer(temp) * (conquer(temp) + 2 * conquer(temp - 1));
		return m[num] %= 1000000007;
	}
	else {
		ll temp = (num + 1) / 2;
		m[num] = conquer(temp) * conquer(temp) + conquer(temp - 1) * conquer(temp - 1);
		return m[num] %= 1000000007;
	}
}

int main()
{
	scanf("%lld", &n);

	printf("%lld", conquer(n));
}