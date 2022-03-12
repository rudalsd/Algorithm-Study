#include <iostream>

using namespace std;

int arr[13][20];
int D, W, K;
int cnt;
int m;

int Check()
{
	for (int i = 0; i < W; i++) {
		int cnt = 0;
		int before = arr[0][i];
		int max = 0;
		for (int j = 0; j < D; j++) {
			if (before == arr[j][i]) {
				cnt++;
			}
			else {
				cnt = 1;
			}
			if (max < cnt) {
				max = cnt;
			}
			before = arr[j][i];
		}
		if (max < K) {
			return 0;
		}
	}

	return 1;
}

void dfs(int level)
{
	if (cnt > m) return;

	if (level == D)
	{
		if (Check()) {
			if (m > cnt) {
				m = cnt;
			}
		}
		return;
	}

	int before[13][20];

	for (int i = 0; i < W; i++) {
		before[level][i] = arr[level][i];
	}

	for (int i = 0; i < 3; i++) {
		if (i == 1 || i == 2) {
			for (int j = 0; j < W; j++) {
				arr[level][j] = i - 1;
			}
			cnt++;
		}
		dfs(level + 1);
		if (i == 1 || i == 2) {
			for (int j = 0; j < W; j++) {
				arr[level][j] = before[level][j];
			}
			cnt--;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> D >> W >> K;
		cnt = 0;
		m = 999;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}

		if (Check()) {
			m = 0;
		}
		else {
			dfs(0);
		}

		cout << "#" << t << " " << m << endl;
	}
}