#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<int, int> A;		//전깃줄이 연결된 번호
map<int, int> idx;		//LIS에서의 index를 저장할 map
vector<int> LIS;
vector<int> ans;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		A[a] = b;
	}

	for (auto it = A.begin(); it != A.end(); it++) {
		if (LIS.size() == 0) {
			LIS.push_back(it->second);
			idx[it->first] = 1;
		}
		else {
			if (*LIS.rbegin() < it->second) {
				LIS.push_back(it->second);
				idx[it->first] = LIS.size();
			}
			else {
				int a = lower_bound(LIS.begin(), LIS.end(), it->second) - LIS.begin();
				LIS[a] = it->second;
				idx[it->first] = a + 1;
			}
		}
	}

	int cnt = LIS.size();

	for (auto it = idx.rbegin(); it != idx.rend(); it++) {
		if (it->second == cnt) {		//뒤에서부터 LIS index를 하나씩 줄여가면서
			cnt--;
		}
		else {					//원했던 index와 다르다면 ans에 push
			ans.push_back(it->first);
		}
	}

	printf("%d\n", ans.size());		//없애야하는 전깃줄의 개수 출력

	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d\n", ans[i]);		//뒤에서부터 ans에 저장된 전깃줄 출력
	}
}