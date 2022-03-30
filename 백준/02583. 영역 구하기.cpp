#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int arr[110][110];				//모눈종이
int visited[110][110];			//방문 여부
int dy[4] = { -1,1,0,0 };		//방향 배열
int dx[4] = { 0,0,-1,1 };
vector<int> area;				//넓이 저장

struct pos {
	int y;
	int x;
};

int bfs(int y, int x)			//넓이 구하기 위한 bfs
{
	queue<pos> q;
	q.push({ y,x });
	visited[y][x] = 1;
	int cnt = 1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < M && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1 && arr[yy][xx] == 0) {
					visited[yy][xx] = 1;
					arr[yy][xx] = 1;
					q.push({ yy,xx });
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main()
{
	cin >> M >> N >> K;

	for (int k = 0; k < K; k++) {				//직사각형 덮은 위치를 1로 초기화
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				area.push_back(bfs(i, j));		//모눈종이에 1이 아닌 곳마다 bfs를 돌려서 면적 push
			}
		}
	}

	sort(area.begin(), area.end());				//오름차순으로 sort

	cout << area.size() << endl;
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
}