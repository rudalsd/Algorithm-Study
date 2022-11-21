#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N;
char arr[51][51];
int visited[51][51][4];
vector<pair<int, int>> door;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

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
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '#') {
				door.emplace_back(i, j);
			}
		}
	}

	int y = door[0].first;
	int x = door[0].second;

	priority_queue<pos, vector<pos>, cmp> pq;

	for (int i = 0; i < 4; i++) {
		pq.push({ y,x,0,i });
	}

	while (!pq.empty()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().cnt;
		int dir = pq.top().dir;
		pq.pop();

		if (y == door[1].first && x == door[1].second) {
			printf("%d", cnt);
			return 0;
		}

		if (visited[y][x][dir] == 1) continue;
		visited[y][x][dir] = 1;

		for (int i = 1; i < N; i++) {
			int yy = y + dy[dir] * i;
			int xx = x + dx[dir] * i;

			if (arr[yy][xx] == '*' || yy >= N || yy < 0 || xx >= N || xx < 0) break;
			if (arr[yy][xx] == '!') {
				if (dir == 0 || dir == 1) {
					if (visited[yy][xx][dir] != 1) {
						pq.push({ yy,xx,cnt + 1,2 });
						pq.push({ yy,xx,cnt + 1,3 });
					}
				}
				else {
					if (visited[yy][xx][dir] != 1) {
						pq.push({ yy,xx,cnt + 1,0 });
						pq.push({ yy,xx,cnt + 1,1 });
					}
				}
			}
			if (arr[yy][xx] == '#') {
				pq.push({ yy,xx,cnt });
			}
		}
	}
}