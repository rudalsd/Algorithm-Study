#include<iostream>
#include<unordered_map>

#define ll long long

using namespace std;

ll A, B, C;
unordered_map<ll, ll> m;

ll conquer(ll num)
{
	if (num == 0) return 1;
	if (num == 1) return A % C;
	if (m[num] != 0) return m[num] % C;

	if (num % 2 == 0) {
		m[num] = conquer(num / 2) * conquer(num / 2);
		return m[num] % C;
	}
	else {
		m[num] = conquer(num - 1) * A;
		return m[num] % C;
	}
}

int main()
{
	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld", conquer(B) % C);
}