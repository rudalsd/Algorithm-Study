#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> LIS;
pair<int, int> arr[100];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		arr[i] = { A,B };
	}

	sort(arr, arr + N);

	LIS.push_back(arr[0].second);

	for (int i = 1; i < N; i++) {
		if (LIS[LIS.size() - 1] < arr[i].second) {
			LIS.push_back(arr[i].second);
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), arr[i].second);
			*it = arr[i].second;
		}
	}

	printf("%d", N - (int)LIS.size());
}