#include <iostream>
#include <vector>

using namespace std;

int arr[20][20];
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { 1,-1,-1,1 };
int startX, startY;
int bucket[110];
int N;
int m;

void dfs(int y, int x, int dir, int level)
{
	if (y == startY && x == startX && dir == 3) {
		for (int i = 0; i < 110; i++) {
			if (bucket[i] > 1)return;
		}
		if (level > m) {
			m = level;
		}
		return;
	}

	for (int i = dir; i <= dir + 1; i++) {
		if (i != 4) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				bucket[arr[yy][xx]]++;
				dfs(yy, xx, i, level + 1);
				bucket[arr[yy][xx]]--;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		m = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				startY = i;
				startX = j;
				dfs(i, j, 0, 0);
			}
		}

		cout << "#" << t << " " << m << endl;
	}
}