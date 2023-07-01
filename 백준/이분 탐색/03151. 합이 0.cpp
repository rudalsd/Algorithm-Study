#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

int N;
int arr[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	ll ans = 0;

	for (int i = 0; i < N - 2; i++) {
		int start = i + 1;
		int end = N - 1;

		if (arr[i] > 0) break;

		while (start < end) {
			int left = 1;
			int right = 1;
			int sum = arr[i] + arr[start] + arr[end];
			if (sum == 0) {
				if (arr[start] == arr[end]) {
					int temp = end - start;
					ans += (1LL * temp + 1) * (1LL * temp) / 2;
					break;
				}
				while (arr[start] == arr[start + 1]) {
					start++;
					left++;
				}
				while (arr[end] == arr[end - 1]) {
					end--;
					right++;
				}

				ans += 1LL * left * right;
				start++;
				end--;
			}
			else if (sum > 0) {
				end--;
			}
			else {
				start++;
			}
		}
	}

	cout << ans;
}