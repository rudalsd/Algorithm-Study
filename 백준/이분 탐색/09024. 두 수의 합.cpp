#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int t, n, K;
int arr[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int T = 0; T < t; T++) {
		cin >> n >> K;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int s = 0;
		int e = n - 1;
		int ans = 0;
		int min = 322222222;

		while (s < e) {
			int temp = arr[s] + arr[e];

			if (abs(temp - K) < min) {
				ans = 1;
				min = abs(temp - K);
			}
			else if (abs(temp - K) == min) {
				ans++;
			}

			if (K > temp)s++;
			else e--;
		}

		cout << ans << '\n';
	}
}
