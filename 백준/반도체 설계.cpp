#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int idx;
	int num;
};

Node arr[40001];
int dp[40001];

bool cmp(Node left, Node right)
{
	return left.num < right.num;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].num;
		arr[i].idx = i;
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < arr[i].idx; j++) {
			if (max < dp[j]) {
				max = dp[j];
			}
		}
		dp[arr[i].idx] = max + 1;
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout << max;
}