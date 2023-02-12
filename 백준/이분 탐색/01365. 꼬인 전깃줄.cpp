#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[100000];
vector<int> LIS;

//int lower_bound(vector<int> vect, int num)
//{
//	int lo = -1;
//	int hi = vect.size() - 1;
//
//	while (lo + 1 < hi) {
//		int mid = (lo + hi) / 2;
//		if (vect[mid] < num) {
//			lo = mid;
//		}
//		else {
//			hi = mid;
//		}
//	}
//
//	return hi;
//}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	LIS.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		if (LIS[LIS.size() - 1] < arr[i]) {
			LIS.push_back(arr[i]);
		}
		else {
			auto idx = lower_bound(LIS.begin(), LIS.end(), arr[i]);
			*idx = arr[i];
		}
	}

	printf("%d", N - LIS.size());
}