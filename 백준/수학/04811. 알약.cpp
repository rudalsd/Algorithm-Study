#include<iostream>
#define ll long long

using namespace std;

ll comb[61][61];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	comb[0][0] = 1;
	comb[1][0] = 1;
	comb[1][1] = 1;

	for (int i = 2; i < 61; i++) {
		for (int j = 0; j <= i; j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}

	while (1) {
		cin >> N;
		if (N == 0) return 0;

		cout << comb[2 * N][N] / (1LL * N + 1) << '\n';
	}
}