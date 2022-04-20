#include <iostream>
#include <queue>

using namespace std;

char arr[10][10];
char temp[10][10];
int visited[10][10][10][10];									//�� �� ���� ��ġ�� ���� ����ϴ� visited�迭
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

	for (int i = 0; i < N; i++) {								//���� ���� ���� ����
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
	q.push({ rY,rX,bY,bX,0 });									//�� �� ���� ��ġ�� q�� �ֱ�

	while (!q.empty())
	{
		int RY = q.front().ry;
		int RX = q.front().rx;
		int BY = q.front().by;
		int BX = q.front().bx;
		int cnt = q.front().cnt;

		q.pop();
		if (cnt > 10) continue;
		if (RY == BY && RX == BX) continue;						//���� ��ġ�� continue
		if (visited[RY][RX][BY][BX] == 1) continue;				//�̹� ��������� ����̸� continue
		visited[RY][RX][BY][BX] = 1;
		if (arr[BY][BX] == 'O') continue;						//�Ķ� ���� ���� ���� continue
		if (arr[RY][RX] == 'O') {								//���� ���� ���� res = 1
			res = 1;
			break;
		}

		int RYY, RXX, BYY, BXX;

		for (int i = 0; i < 4; i++) {							//����� �� ���� ���� �ʱ�ȭ
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
			temp[RY][RX] = '.';									//�ѹ� ����� �� ����
			temp[RYY][RXX] = 'R';
			temp[BY][BX] = '.';
			temp[BYY][BXX] = 'B';
			for (int j = 1; j < 10; j++) {						//���� �������� �ѹ� �� ����̱�
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