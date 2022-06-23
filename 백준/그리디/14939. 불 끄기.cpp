#include<iostream>

using namespace std;

char arr[10][10];
char temp[10][10];
int dy[5] = { -1,1,0,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int cnt;
int ans = 999;

void turn(int y, int x)		//스위치를 누르면 상태 변경
{
	for (int i = 0; i < 5; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= 0 && yy < 10 && xx >= 0 && xx < 10) {
			if (temp[yy][xx] == 'O') {
				temp[yy][xx] = '#';
			}
			else {
				temp[yy][xx] = 'O';
			}
		}
	}
}

int check()		//전구를 다 끌 수 있는지 체크 후 0 또는 1 return
{
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (temp[i - 1][j] == 'O') {
				turn(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (temp[9][i] == 'O') {
			return 0;
		}
	}

	return 1;
}


//void dfs(int level)
//{
//	if (level == 10) {
//		int ch = check(cnt);
//		if (ch) {
//			ans = min(ans, ch);
//		}
//		return;
//	}
//
//	for (int i = 0; i < 2; i++) {
//		if (i == 0) {
//			turn(0, level, arr);
//			cnt++;
//			dfs(level + 1);
//			turn(0, level, arr);
//			cnt--;
//		}
//		else {
//			dfs(level + 1);
//		}
//	}
//}

int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	for (int t = 0; t < 1024; t++) {		//모든 경우의 수
		cnt = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 10; i++) {
			if (t & (1 << i)) {
				turn(0, i);
				cnt++;
			}
		}

		if (!check()) continue;		//check()가 0이면 continue

		ans = min(ans, cnt);
	}

	if (ans == 999) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}