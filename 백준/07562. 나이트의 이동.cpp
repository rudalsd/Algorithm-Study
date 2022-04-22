#include <iostream>
#include <queue>

using namespace std;

struct pos {
	int y;
	int x;
	int cnt;
};

int dy[8] = { -2,-1,1,2,2,1,-1,-2 };										//방향 배열
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };

int main()
{
	int T, l, sy, sx, ey, ex;												//케이스, 판의 한 변의 길이, 시작y, 시작x, 도착y, 도착x
	cin >> T;

	for (int t = 0; t < T; t++) {
		int res = 0;
		cin >> l >> sy >> sx >> ey >> ex;

		int visited[301][301] = { 0 };
		queue<pos> q;

		q.push({ sy,sx,0 });

		while (!q.empty())
		{
			int curY = q.front().y;
			int curX = q.front().x;
			int cnt = q.front().cnt;
			q.pop();

			if (curY == ey && curX == ex) {									//도착점 도착 시 결괏값 저장 후 break;
				res = cnt;
				break;
			}

			if (visited[curY][curX] == 1) continue;							//방문한 노드면 continue
			visited[curY][curX] = 1;

			for (int i = 0; i < 8; i++) {
				int yy = curY + dy[i];
				int xx = curX + dx[i];
				if (yy >= 0 && yy < l && xx >= 0 && xx < l) {
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}

		cout << res << endl;
	}
}