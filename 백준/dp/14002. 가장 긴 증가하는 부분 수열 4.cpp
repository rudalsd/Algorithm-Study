#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int arr[1000];
int order[1000];	//헤당 idx의 숫자의 LIS에서의 순서
vector<int> ans;	//최장 부분 증가 수열
vector<int> LIS;	//lower_bound

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	LIS.push_back(arr[0]);
	order[0] = 1;

	for (int i = 1; i < N; i++) {
		if (LIS[LIS.size() - 1] < arr[i]) {
			LIS.push_back(arr[i]);
			order[i] = LIS.size();
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]);
			int idx = it - LIS.begin();
			*it = arr[i];
			order[i] = idx + 1;
		}
	}

	int cnt = LIS.size();

	printf("%d\n", LIS.size());

	for (int i = N - 1; i >= 0; i--) {
		if (order[i] == cnt) {
			ans.push_back(arr[i]);
			cnt--;
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
}