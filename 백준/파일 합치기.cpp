#include <iostream>
#include <algorithm>

using namespace std;

int arr[550];
int sum[550];
int Data[550][550];

int dp(int start, int end)
{
	if (start == end) return arr[start];

	if (Data[start][end] != 0) return Data[start][end];

	int result = 987654321;

	int Sum = sum[end] - sum[start - 1];

	for (int i = start; i < end; i++) {
		result = min(result, dp(start, i) + dp(i + 1, end) + Sum);
	}
	Data[start][end] = result;
	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int K;
		cin >> K;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				Data[i][j] = 0;
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> arr[i];
			if (i == 0) {
				sum[i] = arr[i];
			}
			else {
				sum[i] = arr[i] + sum[i - 1];
			}
		}

		int result = 987654321;

		for (int i = 0; i < K - 1; i++) {
			result = min(result, dp(0, i) + dp(i + 1, K - 1));
		}

		cout << result << endl;
	}
}