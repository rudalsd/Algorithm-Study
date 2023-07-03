#include<iostream>
#include<algorithm>

using namespace std;

int N, M, L;
int arr[152];

bool check(int mid)
{
	int base = arr[0];
	int cnt = 0;

	for (int i = 0; i <= N; i++) {
		while (1) {
			base += mid;
			if (base >= arr[i + 1]) break;
			cnt++;
		}

		if (cnt > M) return false;
		base = arr[i + 1];
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> L;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	arr[0] = 0;
	arr[N + 1] = L;

	sort(arr, arr + N + 2);

	int left = 1;
	int right = 1000;
	int ans = 987654321;

	while (left < right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			ans = min(ans, mid);
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans;
}
