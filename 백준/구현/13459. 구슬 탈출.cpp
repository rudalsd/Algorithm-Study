#include <iostream>
#include <queue>

using namespace std;

char arr[10][10];
char temp[10][10];
int visited[10][10][10][10];									//공 두 개의 위치를 각각 기록하는 visited배열
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct pos {
	int ry;
	int rx;
	int by;
	int bx;
	int cnt;
};

int main()
{
	int N, M;
	cin >> N >> M;

	int rY, rX, bY, bX;
	int res = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {								//공이 없는 맵을 저장
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'R') {
				arr[i][j] = '.';
				rY = i;
				rX = j;
			}
			if (arr[i][j] == 'B') {
				arr[i][j] = '.';
				bY = i;
				bX = j;
			}
		}
	}

	queue<pos> q;
	q.push({ rY,rX,bY,bX,0 });									//공 두 개의 위치를 q에 넣기

	while (!q.empty())
	{
		int RY = q.front().ry;
		int RX = q.front().rx;
		int BY = q.front().by;
		int BX = q.front().bx;
		int cnt = q.front().cnt;

		q.pop();
		if (cnt > 10) continue;
		if (RY == BY && RX == BX) continue;						//공이 겹치면 continue
		if (visited[RY][RX][BY][BX] == 1) continue;				//이미 만들어졌던 방식이면 continue
		visited[RY][RX][BY][BX] = 1;
		if (arr[BY][BX] == 'O') continue;						//파란 공이 먼저 들어가면 continue
		if (arr[RY][RX] == 'O') {								//빨간 공만 들어가면 res = 1
			res = 1;
			break;
		}

		int RYY, RXX, BYY, BXX;

		for (int i = 0; i < 4; i++) {							//기울일 때 마다 맵을 초기화
			for (int k = 0; k < N; k++) {
				for (int j = 0; j < M; j++) {
					temp[k][j] = arr[k][j];
				}
			}
			temp[RY][RX] = 'R';
			temp[BY][BX] = 'B';
			for (int j = 1; j < 10; j++) {
				RYY = RY + dy[i] * j;
				RXX = RX + dx[i] * j;
				if (temp[RYY][RXX] == '#' || temp[RYY][RXX] == 'B') {
					RYY -= dy[i];
					RXX -= dx[i];
					break;
				}
				else if (temp[RYY][RXX] == 'O') {
					RYY = 0;
					RXX = 0;
					break;
				}
			}
			for (int j = 1; j < 10; j++) {
				BYY = BY + dy[i] * j;
				BXX = BX + dx[i] * j;
				if (temp[BYY][BXX] == '#' || temp[BYY][BXX] == 'R') {
					BYY -= dy[i];
					BXX -= dx[i];
					break;
				}
				else if (temp[BYY][BXX] == 'O') {
					BYY = 0;
					BXX = 0;
					break;
				}
			}
			temp[RY][RX] = '.';									//한번 기울인 후 갱신
			temp[RYY][RXX] = 'R';
			temp[BY][BX] = '.';
			temp[BYY][BXX] = 'B';
			for (int j = 1; j < 10; j++) {						//같은 방향으로 한번 더 기울이기
				RYY = RY + dy[i] * j;
				RXX = RX + dx[i] * j;
				if (temp[RYY][RXX] == '#' || temp[RYY][RXX] == 'B') {
					RYY -= dy[i];
					RXX -= dx[i];
					break;
				}
				else if (temp[RYY][RXX] == 'O') {
					break;
				}
			}
			for (int j = 1; j < 10; j++) {
				BYY = BY + dy[i] * j;
				BXX = BX + dx[i] * j;
				if (temp[BYY][BXX] == '#' || temp[BYY][BXX] == 'R') {
					BYY -= dy[i];
					BXX -= dx[i];
					break;
				}
				else if (temp[BYY][BXX] == 'O') {
					break;
				}
			}
			q.push({ RYY,RXX,BYY,BXX,cnt + 1 });
		}
	}

	cout << res;
}