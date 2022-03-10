#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int y;
	int x;
	int dist;
};

struct cmp {
	bool operator()(pos right, pos left) {
		return left.dist < right.dist;
	}
};

char arr[50][51];
int map[50][50];
int visited[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M;

int main()
{
	cin >> N >> M;
	int y = 0, x = 0;

	priority_queue<pos, vector<pos>, cmp> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'S') {
				y = i;
				x = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'g') {
				map[i][j] = 5000;
				for (int k = 0; k < 4; k++) {
					int yy = i + dy[k];
					int xx = j + dx[k];
					if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
						if (arr[yy][xx] == '.') {
							map[yy][xx] = 1;
						}
					}
				}
			}
		}
	}

	pq.push({ y,x,0 });
	visited[y][x] = 1;

	int answer = 0;

	while (!pq.empty())
	{
		int curY = pq.top().y;
		int curX = pq.top().x;
		int curDist = pq.top().dist;
		pq.pop();

		if (arr[curY][curX] == 'F') {
			answer = curDist;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[yy][xx] != 1) {
					pq.push({ yy,xx,curDist + map[yy][xx] });
					visited[yy][xx] = 1;
				}
			}
		}
	}

	cout << answer / 5000 << " " << answer % 5000;
}