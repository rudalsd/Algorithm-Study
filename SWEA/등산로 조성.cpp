#include <iostream>
#include <vector>

using namespace std;

int arr[8][8];
int N, K;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int m = 0;
int visited[8][8];

struct pos {
	int y;
	int x;
};

void dfs(int y, int x, int level, int flag)
{
	if (m < level) {
		m = level;
	}

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= 0 && xx >= 0 && yy < N && xx < N) {
			if (arr[yy][xx] < arr[y][x] && visited[yy][xx] != 1) {
				visited[yy][xx]++;
				dfs(yy, xx, level + 1, flag);
				visited[yy][xx]--;
			}
			if (arr[yy][xx] - K < arr[y][x] && arr[yy][xx] >= arr[y][x] && visited[yy][xx] != 1 && flag == 0) {
				visited[yy][xx]++;
				int temp = arr[yy][xx];
				arr[yy][xx] = arr[y][x] - 1;
				dfs(yy, xx, level + 1, 1);
				arr[yy][xx] = temp;
				visited[yy][xx]--;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> K;

		vector<pos> vect;

		int max = 0;
		m = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				if (max < arr[i][j]) {
					max = arr[i][j];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == max) {
					vect.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < vect.size(); i++) {
			visited[vect[i].y][vect[i].x]++;
			dfs(vect[i].y, vect[i].x, 1, 0);
			visited[vect[i].y][vect[i].x]--;
		}

		cout << "#" << t << " " << m << endl;
	}
}