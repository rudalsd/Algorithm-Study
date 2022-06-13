#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

void bfs(int y, int x)		//치즈에 둘러쌓여 있지 않은 공간을 2로 초기화
{
	queue<pos> q;
	memset(visited, 0, sizeof(visited));
	q.push({ y,x });
	visited[y][x] = 1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		map[curY][curX] = 2;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (map[yy][xx] != 1 && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int check()		//치즈가 다 녹았는지 체크하는 함수
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				return 0;
			}
		}
	}

	return 1;
}

int Cnt(int y, int x)	//실내 온도에 노출 된 횟수를 출력
{
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
			if (map[yy][xx] == 2) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;

	while (!check())		//치즈가 다 녹을 때까지
	{
		bfs(0, 0);		//0, 0부터 2로 빈 공간 2로 초기화

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {	//2칸 이상 닿아있다면 녹임
					if (Cnt(i, j) >= 2) {
						map[i][j] = 0;
					}
				}
			}
		}

		cnt++;		//횟수 추가
	}

	cout << cnt;
}