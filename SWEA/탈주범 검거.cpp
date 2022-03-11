#include <iostream>
#include <queue>

using namespace std;

int N, M, R, C, L;
int arr[50][50];

struct pos {
	int y;
	int x;
	int cnt;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		int visited[50][50] = { 0 };

		queue<pos> q;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}

		q.push({ R,C,1 });
		visited[R][C] = 1;
		int cnt = 0;

		while (!q.empty())
		{
			int curY = q.front().y;
			int curX = q.front().x;
			int curCnt = q.front().cnt;
			q.pop();

			if (curCnt > L) break;
			cnt++;

			for (int i = 0; i < 4; i++) {
				int yy = curY + dy[i];
				int xx = curX + dx[i];
				if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
					if (visited[yy][xx] != 1) {
						if (i == 0) {
							if (arr[curY][curX] == 1 || arr[curY][curX] == 2 || arr[curY][curX] == 4 || arr[curY][curX] == 7)
							{
								if (arr[yy][xx] == 1 || arr[yy][xx] == 2 || arr[yy][xx] == 5 || arr[yy][xx] == 6) {
									q.push({ yy,xx,curCnt + 1 });
									visited[yy][xx] = 1;
								}
							}
						}
						else if (i == 1) {
							if (arr[curY][curX] == 1 || arr[curY][curX] == 2 || arr[curY][curX] == 5 || arr[curY][curX] == 6)
							{
								if (arr[yy][xx] == 1 || arr[yy][xx] == 2 || arr[yy][xx] == 4 || arr[yy][xx] == 7) {
									q.push({ yy,xx,curCnt + 1 });
									visited[yy][xx] = 1;
								}
							}
						}
						else if (i == 2) {
							if (arr[curY][curX] == 1 || arr[curY][curX] == 3 || arr[curY][curX] == 7 || arr[curY][curX] == 6)
							{
								if (arr[yy][xx] == 1 || arr[yy][xx] == 3 || arr[yy][xx] == 4 || arr[yy][xx] == 5) {
									q.push({ yy,xx,curCnt + 1 });
									visited[yy][xx] = 1;
								}
							}
						}
						else {
							if (arr[curY][curX] == 1 || arr[curY][curX] == 3 || arr[curY][curX] == 4 || arr[curY][curX] == 5)
							{
								if (arr[yy][xx] == 1 || arr[yy][xx] == 3 || arr[yy][xx] == 6 || arr[yy][xx] == 7) {
									q.push({ yy,xx,curCnt + 1 });
									visited[yy][xx] = 1;
								}
							}
						}
					}
				}
			}
		}

		cout << "#" << t << " " << cnt << endl;
	}
}