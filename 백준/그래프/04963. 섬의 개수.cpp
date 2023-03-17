#include<iostream>
#include<queue>

using namespace std;

int arr[50][50];
int dy[8] = { 0,0,-1,1,-1,-1,1,1 };
int dx[8] = { -1,1,0,0,-1,1,1,-1 };
int w, h;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	arr[y][x] = 0;

	while (!q.empty()) {
		const int y = q.front().first;
		const int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy < h && xx >= 0 && xx < w) {
				if (arr[yy][xx] == 1) {
					arr[yy][xx] = 0;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	while (1) {
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0) return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
}