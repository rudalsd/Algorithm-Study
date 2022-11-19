#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int W, H;
char arr[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[101][101][4];
vector<pair<int, int>> laser;

struct pos {
	int y;
	int x;
	int cnt;
	int dir;
};

struct cmp {
	bool operator()(pos right, pos left) {
		return left.cnt < right.cnt;
	}
};

int main()
{
	scanf("%d %d", &W, &H);

	for (int i = 0; i < H; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == 'C') {
				laser.emplace_back(i, j);
			}
		}
	}

	priority_queue<pos, vector<pos>, cmp> pq;
	for (int i = 0; i < 4; i++) {
		pq.push({ laser[0].first, laser[0].second, 0, i });
	}

	while (!pq.empty()) {
		const int y = pq.top().y;
		const int x = pq.top().x;
		const int cnt = pq.top().cnt;
		const int dir = pq.top().dir;
		pq.pop();

		if (visited[y][x][dir] == 1) continue;
		visited[y][x][dir] = 1;

		if (y == laser[1].first && x == laser[1].second) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < H && xx >= 0 && xx < W) {
				if (arr[yy][xx] == '*') continue;
				if (visited[yy][xx][dir] != 1) {
					if (i != dir) {
						pq.push({ yy,xx,cnt + 1,i });
					}
					else {
						pq.push({ yy,xx,cnt,i });
					}
				}
			}
		}
	}
}