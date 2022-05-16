#include <iostream>
#include <vector>

using namespace std;

int arr[1000];
int dp[1000];

int main()
{
	dp[0] = 1;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (max < dp[j]) {
					max = dp[j];
				}
			}
		}
		dp[i] = max + 1;
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (max < dp[i])
		{
			max = dp[i];
		}
	}

	cout << max;
}