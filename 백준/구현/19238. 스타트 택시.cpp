#include<iostream>
#include<queue>

using namespace std;

int N, M, F;
int arr[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int curY, curX;
pair<int, int> start[401];
pair<int, int> des[401];
int box[401];

struct pos {
	int y;
	int x;
	int cnt;
};

int bfs(int y, int x, int desY, int desX)	//목적지 까지의 거리 return
{
	queue<pos> q;
	q.push({ y,x,0 });
	int visited[21][21] = { 0 };
	visited[y][x] = 1;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (y == desY && x == desX) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
				if (arr[yy][xx] != 1 && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}

	return -1;
}

int main()
{
	scanf("%d %d %d", &N, &M, &F);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d %d", &curY, &curX);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d %d", &start[i].first, &start[i].second, &des[i].first, &des[i].second);
	}

	while (1) {
		int destination = 0;
		int min = 987654321;
		for (int i = 1; i <= M; i++) {
			if (box[i] != 1) {
				int temp = bfs(curY, curX, start[i].first, start[i].second);
				if (min > temp) {	//더 가까우면
					min = temp;
					destination = i;
				}
				else if (min == temp) {		//거리가 같다면
					if (start[destination].first > start[i].first) {
						destination = i;
					}
					else if (start[destination].first == start[i].first) {
						if (start[destination].second > start[i].second) {
							destination = i;
						}
					}
				}
			}
			if (min <= 0) break;
		}

		if (min == -1) {	//목적지로 갈 수 없다면
			printf("%d", -1);
			return 0;
		}

		curY = start[destination].first;
		curX = start[destination].second;
		F -= min;
		box[destination] = 1;

		if (F <= 0) {	//연료가 다 떨어지면
			printf("%d", -1);
			return 0;
		}

		int temp = bfs(curY, curX, des[destination].first, des[destination].second);

		if (temp == -1) {
			printf("%d", -1);
			return 0;
		}

		F -= temp;

		if (F < 0) {
			printf("%d", -1);
			return 0;
		}

		curY = des[destination].first;
		curX = des[destination].second;

		F += (temp * 2);

		int cnt = 0;

		for (int i = 1; i <= M; i++) {
			if (box[i] == 1) {
				cnt++;
			}
		}

		if (cnt == M) break;
	}

	printf("%d", F);
}