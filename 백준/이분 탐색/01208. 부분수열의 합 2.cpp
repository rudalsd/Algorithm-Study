#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, S;
int arr[41];
unordered_map<int, int> map;
int sum = 0;
long long cnt = 0;

void leftDFS(int level)				//���� ���� ��� ������ map�� ����
{
	if (level == N / 2) {
		map[sum]++;
		return;
	}

	sum += arr[level];
	leftDFS(level + 1);
	sum -= arr[level];
	leftDFS(level + 1);
}

void rightDFS(int level)			//������ ���� ��� ������ S�� ����
{									//cnt�� ������
	if (level == N) {
		cnt += map[S - sum];
		return;
	}

	sum += arr[level];
	rightDFS(level + 1);
	sum -= arr[level];
	rightDFS(level + 1);
}

int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	leftDFS(0);
	rightDFS(N / 2);

	if (S == 0) cnt--;				//S�� 0�� ��� �������� 2�� ���Ƿ� 1�� ���ش�.

	cout << cnt;
}