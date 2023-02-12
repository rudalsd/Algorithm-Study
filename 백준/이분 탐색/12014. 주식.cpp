#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, K;
		int num;
		vector<int> LIS;

		scanf("%d %d", &N, &K);

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

		printf("Case #%d\n", t);

		if (LIS.size() >= K) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
}