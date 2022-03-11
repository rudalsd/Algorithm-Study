#include <iostream>

using namespace std;

int N;
int arr[102][102];

int pinball(int y, int x, int dir)
{
	int cnt = 0;
	int startY = y;
	int startX = x;
	while (1)
	{
		if (dir == 0) {
			y -= 1;
		}
		else if (dir == 1) {
			y += 1;
		}
		else if (dir == 2) {
			x -= 1;
		}
		else {
			x += 1;
		}

		if (arr[y][x] == -1 || (y == startY && x == startX)) {
			return cnt;
		}
		else if (arr[y][x] == 0) continue;
		else if (arr[y][x] > 0 && arr[y][x] < 6) {
			if (arr[y][x] == 1) {
				if (dir == 0) {
					dir = 1;
				}
				else if (dir == 1) {
					dir = 3;
				}
				else if (dir == 2) {
					dir = 0;
				}
				else {
					dir = 2;
				}
			}
			else if (arr[y][x] == 2) {
				if (dir == 0) {
					dir = 3;
				}
				else if (dir == 1) {
					dir = 0;
				}
				else if (dir == 2) {
					dir = 1;
				}
				else {
					dir = 2;
				}
			}
			else if (arr[y][x] == 3) {
				if (dir == 0) {
					dir = 2;
				}
				else if (dir == 1) {
					dir = 0;
				}
				else if (dir == 2) {
					dir = 3;
				}
				else {
					dir = 1;
				}
			}
			else if (arr[y][x] == 4) {
				if (dir == 0) {
					dir = 1;
				}
				else if (dir == 1) {
					dir = 2;
				}
				else if (dir == 2) {
					dir = 3;
				}
				else {
					dir = 0;
				}
			}
			else if (arr[y][x] == 5) {
				if (dir == 0) {
					dir = 1;
				}
				else if (dir == 1) {
					dir = 0;
				}
				else if (dir == 2) {
					dir = 3;
				}
				else {
					dir = 2;
				}
			}
			cnt++;
		}

		int flag = 0;
		if (arr[y][x] > 5 && arr[y][x] <= 10) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if (i != y || j != x) {
						if (arr[i][j] == arr[y][x]) {
							y = i;
							x = j;
							flag = 1;
							break;
						}
					}
				}
				if (flag == 1) {
					break;
				}
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

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N + 2; i++) {
			arr[0][i] = 5;
			arr[N + 1][i] = 5;
			arr[i][0] = 5;
			arr[i][N + 1] = 5;
		}

		int max = 0;

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				if (arr[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int cnt = pinball(i, j, k);
						if (cnt > max) {
							max = cnt;
						}
					}
				}
			}
		}

		cout << "#" << t << " " << max << endl;
	}
}