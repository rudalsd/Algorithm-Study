#include<iostream>
#include<unordered_map>
#define ll long long

using namespace std;

ll N;
int P, Q;
unordered_map<ll, ll> um;

ll dfs(ll n)
{
	if (um.count(n)) return um[n];

	return um[n] = dfs(n / P) + dfs(n / Q);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q;

	um[0] = 1;

	cout << dfs(N);
}
