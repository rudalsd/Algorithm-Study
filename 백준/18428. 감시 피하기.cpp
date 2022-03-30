#include <iostream>

using namespace std;

char arr[6][6];
int N;
int visited[6][6];

struct pos {
	int y;
	int x;
};

int cnt;
int result;

pos position[10];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int check(int y, int x)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < N; j++) {
			int yy = y + dy[i] * j;
			int xx = x + dx[i] * j;
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (arr[yy][xx] == 'O') {
					break;
				}
				else if (arr[yy][xx] == 'S') {
					return 0;
				}
			}
		}
	}

	return 1;
}

void dfs(int level, int t)
{
	if (result == 1) return;
	if (level == 3)
	{
		for (int i = 0; i < cnt; i++) {
			result = check(position[i].y, position[i].x);
			if (result == 0) {
				break;
			}
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i * N + j > t && arr[i][j] == 'X' && visited[i][j] != 1) {
				visited[i][j] = 1;
				arr[i][j] = 'O';
				dfs(level + 1, i * N + j);
				visited[i][j] = 0;
				arr[i][j] = 'X';
			}
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') {
				position[cnt++] = { i,j };
			}
		}
	}

	dfs(0, -1);

	if (result == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}