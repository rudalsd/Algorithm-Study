#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> lis;
vector<int> ans;
int arr[1000001];		//전체 배열
int index[1000001];		//lis 좌표를 저장하기 위한 배열


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			lis.push_back(arr[i]);
			index[i] = lis.size();		//lis의 몇번 째에 있는지 저장
		}
		else {
			if (*lis.rbegin() < arr[i]) {
				lis.push_back(arr[i]);
				index[i] = lis.size();	//lis의 몇번 째에 있는지 저장
			}
			else {
				auto idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
				lis[idx] = arr[i];
				index[i] = idx + 1;		//lis의 몇번 째에 있는지 저장
			}
		}
	}

	int cnt = lis.size();

	for (int i = N - 1; i >= 0; i--) {	//반대부터 index를 1씩 줄여가며 순서대로 저장
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