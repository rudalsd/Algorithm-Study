#include<iostream>
#include<vector>
#include<map>
#define M 1000000
#define ll long long

using namespace std;

ll n;
vector<vector<ll>> mat = { {1,1},{1,0} };
map<ll, vector<vector<ll>>> m;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> ret = { {0,0},{0,0} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ret[i][j] = (((a[i][0] % M) * (b[0][j] % M)) % M + ((a[i][1] % M) * (b[1][j] % M)) % M) % M;
		}
	}

	return ret;
}

vector<vector<ll>> conquer(ll n)
{
	if (m[n].size() != 0) return m[n];
	if (n == 1) return mat;
	if (n == 0) return { {1,0},{0,1} };
	if (n % 2 == 0) {
		return m[n] = mul(conquer(n / 2), conquer(n / 2));
	}
	else {
		return m[n] = mul(conquer(n - 1), conquer(1));
	}
}

int main()
{
	scanf("%lld", &n);

	vector<vector<ll>> ans = conquer(n);
	
	printf("%d", ans[0][1]);
}