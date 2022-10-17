#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int arr[200];
vector<int> lis;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	lis.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		if (lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			auto idx = lower_bound(lis.begin(), lis.end(), arr[i]);
			*idx = arr[i];
			int de = -1;
		}
	}

	printf("%d", N - lis.size());
}