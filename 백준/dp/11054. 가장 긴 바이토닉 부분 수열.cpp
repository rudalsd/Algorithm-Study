#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000];
int increase[1000];
int decrease[1000];
vector<int> mem;

int N;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int max = 1;

	for (int i = 0; i < N; i++) {		//�����ϴ� �κ� ������ �ִ� ���� increase�� ����
		if (i == 0) {
			mem.push_back(arr[i]);
		}
		else {
			if (mem[mem.size() - 1] < arr[i]) {
				max++;
				mem.push_back(arr[i]);
			}
			else {
				int idx = lower_bound(mem.begin(), mem.end(), arr[i]) - mem.begin();
				mem[idx] = arr[i];
			}
		}
		increase[i] = max;
	}

	max = 1;
	mem.clear();

	for (int i = N - 1; i >= 0; i--) {	//�����ϴ� �κ� ������ �ִ� ���� decrease�� ����
		if (i == N - 1) {
			mem.push_back(arr[i]);
		}
		else {
			if (mem[mem.size() - 1] < arr[i]) {
				max++;
				mem.push_back(arr[i]);
			}
			else {
				int idx = lower_bound(mem.begin(), mem.end(), arr[i]) - mem.begin();
				mem[idx] = arr[i];
			}
		}
		decrease[i] = max;
	}

	max = 0;

	for (int i = 0; i < N; i++) {		//�� ������ ���� ������ ���� ������ ���� �ϳ� ��ġ�Ƿ� -1�� ����
		if (max < increase[i] + decrease[i] - 1) {
			max = increase[i] + decrease[i] - 1;	//�ִ� ����
		}
	}

	cout << max;
}