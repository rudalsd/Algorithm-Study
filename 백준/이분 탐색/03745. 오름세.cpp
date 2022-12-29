#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	while (1) {
		int n;
		vector<int> LIS;
		if (scanf("%d", &n) != 1) {
			break;
		}
		
		int num;
		scanf("%d", &num);

		LIS.push_back(num);

		for (int i = 1; i < n; i++) {
			scanf("%d", &num);
			if (LIS[LIS.size() - 1] < num) {
				LIS.push_back(num);
			}
			else {
				auto idx = lower_bound(LIS.begin(), LIS.end(), num);
				*idx = num;
			}
		}

		printf("%d\n", LIS.size());
	}
}