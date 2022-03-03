#include <iostream>
#include <queue>

using namespace std;

class pos {
public:
	int y;
	int x;
	int cnt;
	int water = 0;
	pos(int a, int b, int c)
	{
		y = a;
		x = b;
		cnt = c;
	}
};

char map[60][60];
int R, C;

int main()
{
	int visited[50][50] = { 0 };
	queue<pos> q;
	cin >> R >> C;
	int y1 = 0, x1 = 0;
	int y2 = 0, x2 = 0;
	int dy[4] = { 0,0,-1,1 };
	int dx[4] = { -1,1,0,0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*')
			{
				pos start(i, j, 0);
				start.water = 1;
				map[i][j] = '*';
				q.push(start);
			}
			if (map[i][j] == 'S') {
				y1 = i;
				x1 = j;
			}
		}
	}

	pos start(y1, x1, 0);
	visited[y1][x1] = 1;
	q.push(start);

	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		int cnt = q.front().cnt;
		int water = q.front().water;
		q.pop();

		if (map[cy][cx] == 'D') {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int yy = cy + dy[i];
			int xx = cx + dx[i];
			if (yy >= 0 && yy < R && xx >= 0 && xx < C) {
				if (water == 1) {
					if (map[yy][xx] == '.') {
						map[yy][xx] = '*';
						pos next(yy, xx, 0);
						next.water = 1;
						q.push(next);
					}
				}

				else {
					if ((map[yy][xx] == 'D' || map[yy][xx] == '.') && visited[yy][xx] == 0) {
						visited[yy][xx] = 1;
						pos next(yy, xx, cnt + 1);
						q.push(next);
					}
				}
			}
		}
	}

	cout << "KAKTUS";
}