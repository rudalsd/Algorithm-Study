#include<iostream>

using namespace std;

int arr[9][9];
int sero[9][10];
int garo[9][10];
int square[9][10];
bool flag = false;

void dfs(int num)
{
	if (flag) return;
	if (num == 81) {
		flag = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	int y = num / 9;
	int x = num % 9;

	if (arr[y][x] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (sero[x][i] != 1 && garo[y][i] != 1 && square[(y / 3) * 3 + x / 3][i] != 1) {
				sero[x][i] = 1;
				garo[y][i] = 1;
				square[(y / 3) * 3 + x / 3][i] = 1;
				arr[y][x] = i;
				dfs(num + 1);
				sero[x][i] = 0;
				garo[y][i] = 0;
				square[(y / 3) * 3 + x / 3][i] = 0;
				arr[y][x] = 0;
			}
		}
	}
	else {
		dfs(num + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				sero[j][arr[i][j]] = 1;
				garo[i][arr[i][j]] = 1;
				square[(i / 3) * 3 + j / 3][arr[i][j]] = 1;
			}
		}
	}

	dfs(0);
}