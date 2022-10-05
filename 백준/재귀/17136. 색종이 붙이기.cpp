#include<iostream>

using namespace std;

int arr[10][10];
int cnt[6];
int ans = 987654321;
int cnt1;

void reset(int y, int x, int n)		//덮었던 색종이를 제거
{
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			arr[i][j] = 1;
		}
	}
}

void change(int y, int x, int n)	//색종이 덮기
{
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			arr[i][j] = 0;
		}
	}
}

bool stick(int y, int x, int n)	//색종이를 붙일 수 있는지 없는지 체크
{
	if (y + n > 10 || x + n > 10) return false;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

bool check()	//색종이가 다 덮였는지 체크
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				return false;
			}
		}
	}

	return true;
}

void dfs(int level, int cur)
{
	if (cur == 100 && check()) {	//마지막 좌표에 도착 및 모두 덮였을 때
		ans = min(ans, level);
		return;
	}
	if (cur == 100) return;

	if (arr[cur / 10][cur % 10] == 0) dfs(level, cur + 1);	//덮을 필요 없는 좌표

	for (int i = 5; i >= 1; i--) {
		if (cnt[i] <= 4) {
			if (arr[cur / 10][cur % 10] == 1) {	//덮어야하는 좌표
				if (stick(cur / 10, cur % 10, i)) {
					cnt[i]++;
					change(cur / 10, cur % 10, i);
					dfs(level + 1, cur + 1);
					reset(cur / 10, cur % 10, i);
					cnt[i]--;
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0);

	if (ans != 987654321) {
		printf("%d", ans);
	}
	else {
		printf("%d", -1);
	}
}