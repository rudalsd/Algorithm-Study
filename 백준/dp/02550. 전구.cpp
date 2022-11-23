#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int sw[10001];		//sw[i] = 스위치 번호
int pos[10001];		//pos[스위치 번호] = i
int bulb[10001];	//전구의 순서
int idx[10001];		//LIS에서 몇번 째 위치해 있는지 저장할 배열
vector<int> LIS;
vector<int> ans;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int idx;
		scanf("%d", &idx);
		sw[i] = idx;
		pos[idx] = i;
	}

	for (int i = 0; i < N; i++) {
		int idx;
		scanf("%d", &idx);
		bulb[pos[idx]] = i;
	}

	LIS.push_back(bulb[0]);
	idx[0] = 1;

	for (int i = 1; i < N; i++) {		//lower_bound
		if (bulb[i] > LIS[LIS.size() - 1]) {
			LIS.push_back(bulb[i]);
			idx[i] = LIS.size();
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), bulb[i]);
			*it = bulb[i];
			idx[i] = it - LIS.begin() + 1;	//현재 스위치의 LIS에서의 위치
		}
	}

	int cur = LIS.size();

	for (int i = N - 1; i >= 0; i--) {
		if (idx[i] == cur) {
			ans.push_back(sw[i]);
			cur--;
		}
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", LIS.size());

	for (int i = 0; i < LIS.size(); i++) {
		printf("%d ", ans[i]);
	}
}