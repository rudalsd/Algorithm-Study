#include<iostream>

using namespace std;

int main()
{
	int arr[10000];

	int N, M;
	cin >> N >> M;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum == M) {
				cnt++;
				break;
			}
			if (sum > M)
				break;
		}
	}

	cout << cnt;
}