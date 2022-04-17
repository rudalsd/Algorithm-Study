#include<iostream>

using namespace std;

int dy[4] = { -1,1,0,0 };									//방향배열
int dx[4] = { 0,0,-1,1 };
char arr[1000][1000];										//지도
int visited[1000][1000];									//방문 여부 체크 배열
int N, M;
char dir[5] = "UDLR";
int cnt;

struct pos {
	int y;
	int x;
};

void dfs(int y, int x)										//방문한 곳 visited 배열에 기록
{
	visited[y][x] = 1;
	int yy, xx;
	for (int i = 0; i < 4; i++) {
		if (arr[y][x] == dir[i]) {
			yy = y + dy[i];
			xx = x + dx[i];

			if (visited[yy][xx] == 1) {						//처음 만들어진 사이클이면 cnt++
				cnt++;
			}
			else if (visited[yy][xx] == 0) {
				dfs(yy, xx);
			}
		}
	}
	visited[y][x] = 2;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {						//방문하지 않은 곳일 때만 bfs 돌리기
				dfs(i, j);
			}
		}
	}

	cout << cnt;
}