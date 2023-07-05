#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> sum;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			sum.push_back(arr[i] + arr[j]);
		}
	}

	sort(arr, arr + N);
	sort(sum.begin(), sum.end());

	int ans = 0;

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (*lower_bound(sum.begin(), sum.end(), arr[i] - arr[j]) == arr[i]-arr[j]) {
				cout << arr[i];
				return 0;
			}
		}
	}
}
