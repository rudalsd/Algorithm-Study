#include<iostream>
#define ll long long
#define M 1000000007
using namespace std;

ll arr[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W;
	cin >> W;

	arr[0] = 1;
	arr[2] = 3;

	if (W % 2 == 0) {
		for (int i = 4; i <= W; i += 2) {
			arr[i] = ((arr[i - 2] % M) * 4) % M - arr[i - 4] % M + M;
			arr[i] %= M;
		}
	}
	else {
		cout << 0;
		return 0;
	}

	cout << arr[W];
}