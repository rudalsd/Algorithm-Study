#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int main()
{
	vector<int> LIS;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (i == 0) {
			LIS.push_back(num);
		}
		else {
			if (LIS[LIS.size() - 1] < num) {
				LIS.push_back(num);
			}
			else {
				auto idx = lower_bound(LIS.begin(), LIS.end(), num);
				*idx = num;
			}
		}
	}

	printf("%d", LIS.size());
}