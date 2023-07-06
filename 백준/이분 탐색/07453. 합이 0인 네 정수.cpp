#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

int arr[4][4000];
vector<int> sum;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum.push_back(arr[0][i] + arr[1][j]);
		}
	}

	sort(sum.begin(), sum.end());

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = arr[2][i] + arr[3][j];

			auto it = lower_bound(sum.begin(), sum.end(), -temp);

			if (*it == -temp) {
				ans += upper_bound(sum.begin(), sum.end(), -temp) - it;
			}
		}
	}

	cout << ans;
}
