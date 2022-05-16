#include <iostream>
#include <queue>

using namespace std;

struct pos {
	int y;
	int x;
	int time;
};

int arr[550][550];
int cur;
bool sun;
queue<pos> q;
int n, m;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[550][550][2][20];

int check(int y, int x, int dir)
{
	for (int i = 1; i < n; i++) {
		int yy = y + dy[dir] * i;
		int xx = x + dx[dir] * i;
		if (yy >= 0 && yy < n && xx >= 0 && xx < n) {
			if (arr[yy][xx] == 0) {
				return i;
			}
		}
	}

	return 0;
}

int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		int curTime = q.front().time;
		bool day = false;
		q.pop();

		if (curTime % (m * 2) < m) {
			day = true;
		}

		if (visited[curY][curX][day][curTime % m] == 1) continue;
		visited[curY][curX][day][curTime % m] = 1;

		if (curY == n - 1 && curX == n - 1) {
			cur = curTime / (m * 2) + 1;
			sun = day;
			return 1;
		}

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < n && xx >= 0 && xx < n) {
				if (day) {
					if (arr[yy][xx] != 1) {
						q.push({ yy,xx,curTime + 1 });
					}
				}
				else {
					if (arr[yy][xx] == 1) {
						int num = check(curY, curX, i);
						if (num) {
							yy = curY + dy[i] * num;
							xx = curX + dx[i] * num;
							q.push({ yy,xx,curTime + 1 });
						}
					}
					else {
						q.push({ yy,xx,curTime + 1 });
					}
				}
			}
		}
	}

	return 0;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	q.push({ 0,0,0 });

	if (bfs()) {
		cout << cur << " ";
		if (sun) {
			cout << "sun";
		}
		else {
			cout << "moon";
		}
	}
	else {
		cout << -1;
	}
}