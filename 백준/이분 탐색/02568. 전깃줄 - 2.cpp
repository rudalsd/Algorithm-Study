#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<int, int> A;		//�������� ����� ��ȣ
map<int, int> idx;		//LIS������ index�� ������ map
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
		if (it->second == cnt) {		//�ڿ������� LIS index�� �ϳ��� �ٿ����鼭
			cnt--;
		}
		else {					//���ߴ� index�� �ٸ��ٸ� ans�� push
			ans.push_back(it->first);
		}
	}

	printf("%d\n", ans.size());		//���־��ϴ� �������� ���� ���

	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d\n", ans[i]);		//�ڿ������� ans�� ����� ������ ���
	}
}