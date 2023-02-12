#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> LIS;

int main()
{
	scanf("%d", &N);

	int n;

	scanf("%d", &n);

	LIS.push_back(n);

	for (int i = 1; i < N; i++) {
		scanf("%d", &n);
		if (LIS[LIS.size() - 1] < n) {
			LIS.push_back(n);
		}
		else {
			auto idx = lower_bound(LIS.begin(), LIS.end(), n);
			*idx = n;
		}
	}

	printf("%d", LIS.size());
}