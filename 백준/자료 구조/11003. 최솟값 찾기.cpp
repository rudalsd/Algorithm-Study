#include<iostream>

using namespace std;

int arr[10000001];
int N, L;

int getTree(int left, int right)
{
	left += N;
	right += N;
	int ret = 1000000000;

	while (left <= right) {
		if (left & 1) {
			ret = min(arr[left], ret);
			left += 1;
		}
		if (~right & 1) {
			ret = min(arr[right], ret);
			right -= 1;
		}
		left >>= 1;
		right >>= 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> arr[N + i];
	}

	for (int i = N - 1; i >= 1; i--) {
		arr[i] = min(arr[i << 1], arr[i << 1 | 1]);
	}

	for (int i = 0; i < N; i++) {
		cout << getTree(max(0, i - L + 1), i) << ' ';
	}
}