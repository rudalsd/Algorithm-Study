#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[40000];

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		vector<int> LIS;
		LIS.push_back(arr[0]);

		for (int i = 1; i < N; i++) {
			if (LIS[LIS.size() - 1] < arr[i]) {
				LIS.push_back(arr[i]);
			}
			else {
				auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
				*it = arr[i];
			}
		}

		printf("%d\n", (int)LIS.size());
	}
}