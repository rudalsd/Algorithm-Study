#include<iostream>
#include<algorithm>

using namespace std;

int N, C;
int arr[200000];

bool check(int mid)
{
	int base = arr[0];
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (arr[i] - base >= mid) {
			base = arr[i];
			cnt++;
		}

		if (cnt >= C) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int left = 0;
	int right = 1000000001;
	int ans = 0;

	while (left < right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid;
		}
	}

	cout << ans;
}
