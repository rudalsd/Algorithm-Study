#include<iostream>

using namespace std;

int H, W;
int arr[500];
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < W - 1; i++) {
		int left = 0, right = 0;

		for (int j = i - 1; j >= 0; j--) {
			left = max(left, arr[j]);
		}

		for (int j = i + 1; j < W; j++) {
			right = max(right, arr[j]);
		}

		ans += max(min(left, right) - arr[i], 0);
	}

	cout << ans;
}
