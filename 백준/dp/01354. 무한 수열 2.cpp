#include<iostream>
#include<unordered_map>
#define ll long long

using namespace std;

ll N;
int P, Q, X, Y;
unordered_map<ll, ll> um;

ll dfs(ll n)
{
	if (n <= 0) return um[n] = 1;
	if (um.count(n) != 0) return um[n];

	return um[n] = dfs(n / P - X) + dfs(n / Q - Y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P >> Q >> X >> Y;

	cout << dfs(N);
}