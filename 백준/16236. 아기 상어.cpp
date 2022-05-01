#include<iostream>
#include<queue>

using namespace std;

int N;
int arr[50][50];
int ssize = 2;
int cnt = 0;
int Time = 0;
int sy, sx;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int check() {													//먹이가 있는지 없는지 체크
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < ssize && arr[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}

struct pos {
	int y;
	int x;
	int dist;
};

struct cmp {
	bool operator()(pos right, pos left) {
		if (left.dist < right.dist) return true;
		if (left.dist > right.dist) return false;
		if (left.y < right.y) return true;
		if (left.y > right.y) return false;
		return left.x < right.x;
	}
};

int main()
{
	cin >> N;
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {								//상어의 위치를 기록
				sy = i;				
				sx = j;
			}
		}
	}

	while (1) {
		if (check()) {
			break;
		}

		queue<pos> q;
		priority_queue<pos, vector<pos>, cmp> pq;
		q.push({ sy,sx, 0 });
		int visited[21][21] = { 0 };

		while (!q.empty()) {
			int curY = q.front().y;
			int curX = q.front().x;
			int cnt = q.front().dist;
			q.pop();

			if (visited[curY][curX] == 1)continue;
			visited[curY][curX] = 1;

			if (arr[curY][curX] != 9 && arr[curY][curX] != 0 && arr[curY][curX] < ssize) {	//먹이의 위치와 거리를 pq에 푸시
				pq.push({ curY,curX,cnt });
			}
			

			for (int i = 0; i < 4; i++) {
				int yy = curY + dy[i];
				int xx = curX + dx[i];
				if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
					if (arr[yy][xx] <= ssize) {
						q.push({ yy,xx,cnt + 1 });
					}
				}
			}
		}

		if (pq.empty()) {																	//먹을 수 있는 먹이가 없을 때 탈출
			break;
		}

		int dist = pq.top().dist;
		int curY = pq.top().y;
		int curX = pq.top().x;
		Time += dist;
		cnt++;
		arr[sy][sx] = 0;
		arr[curY][curX] = 9;
		sy = curY;
		sx = curX;
		if (ssize == cnt) {										//사이즈만큼 먹이를 먹었다면 사이즈 증가 및 카운트 초기화
			cnt = 0;
			ssize++;
		}
	}

	cout << Time;
}
