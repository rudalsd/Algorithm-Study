#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> lis;
vector<int> ans;
int arr[1000001];		//��ü �迭
int index[1000001];		//lis ��ǥ�� �����ϱ� ���� �迭


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			lis.push_back(arr[i]);
			index[i] = lis.size();		//lis�� ��� °�� �ִ��� ����
		}
		else {
			if (*lis.rbegin() < arr[i]) {
				lis.push_back(arr[i]);
				index[i] = lis.size();	//lis�� ��� °�� �ִ��� ����
			}
			else {
				auto idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
				lis[idx] = arr[i];
				index[i] = idx + 1;		//lis�� ��� °�� �ִ��� ����
			}
		}
	}

	int cnt = lis.size();

	for (int i = N - 1; i >= 0; i--) {	//�ݴ���� index�� 1�� �ٿ����� ������� ����
		if (index[i] == cnt) {
			ans.push_back(arr[i]);
			cnt--;
		}

		if (cnt == 0) break;
	}

	cout << lis.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}