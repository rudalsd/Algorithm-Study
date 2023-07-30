#include<iostream>
#include<algorithm>

using namespace std;

int N, C;
int arr[5000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == C) {
			cout << 1;
			return 0;
		}
	}

	sort(arr, arr + N);

	int s = 0;
	int e = N - 1;

	while (s < e) {
		int temp = arr[s] + arr[e];

		if (temp > C) {
			e--;
		}
		else if (temp < C) {
			s++;
		}
		else {
			cout << 1;
			return 0;
		}
	}

	for (int i = 0; i < N - 2; i++) {
		s = i + 1;
		e = N - 1;

		while (s < e) {
			int temp = arr[i] + arr[s] + arr[e];

			if (temp > C) {
				e--;
			}
			else if (temp < C) {
				s++;
			}
			else {
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;
}