#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> LIS;

int main()
{
	scanf("%d", &N);

	int num;

	scanf("%d", &num);

	LIS.push_back(num);

	for (int i = 1; i < N; i++) {
		scanf("%d", &num);

		if (LIS[LIS.size() - 1] < num) {
			LIS.push_back(num);
		}
		else {
			auto idx = lower_bound(LIS.begin(), LIS.end(), num);
			*idx = num;
		}
	}

	printf("%d", N - LIS.size());
}