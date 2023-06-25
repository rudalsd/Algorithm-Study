#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll N, K;
int M;
ll arr[2001][2001];

vector<int> luca(ll N, int M)
{
	vector<int> ret;

	while (N) {
		int temp = N % M;
		ret.push_back(temp);
		N /= M;
	}

	return ret;
}

ll comb(int N, int R)
{
	if (N < R) return 0;
	if (R == 1) return N;
	if (R == 0) return 1;
	if (arr[N][R] != 0) return arr[N][R];

	return arr[N][R] = (comb(N - 1, R - 1) + comb(N - 1, R)) % M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;

	vector<int> n, k;

	n = luca(N, M);
	k = luca(K, M);

	int idx = min(n.size(), k.size());

	ll ans = 1;

	for (int i = 0; i < idx; i++) {
		ans *= comb(n[i], k[i]);
		ans %= M;
		if (ans == 0) break;
	}

	cout << ans;
}