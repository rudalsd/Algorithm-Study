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

void leftDFS(int level)				//왼쪽 반의 모든 조합을 map에 저장
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

void rightDFS(int level)			//오른쪽 반의 모든 조합을 S와 비교해
{									//cnt에 더해줌
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

	if (S == 0) cnt--;				//S가 0인 경우 공집합이 2번 들어가므로 1을 빼준다.

	cout << cnt;
}