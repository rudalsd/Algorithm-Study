#include<iostream>
#include<queue>

using namespace std;

struct state {
	int Ry;
	int Rx;
	int By;
	int Bx;
	int cnt;
};

int N, M;
char map[10][10];
char temp[10][10];
int visited[10][10][10][10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int Ry;
int Rx;
int By;
int Bx;
int ans;

void move(int num)					//������ �����̱� ���� move �Լ�
{
	for (int i = 1; i < 10; i++) {	//���� ���� �ű��
		int yy = Ry + dy[num] * i;
		int xx = Rx + dx[num] * i;
		if (temp[yy][xx] == 'O') {
			temp[Ry][Rx] = '.';
			Ry = 0;
			Rx = 0;
			break;
		}
		else if (temp[yy][xx] != '.') {
			temp[Ry][Rx] = '.';
			Ry = Ry + dy[num] * (i - 1);
			Rx = Rx + dx[num] * (i - 1);
			temp[Ry][Rx] = 'R';
			break;
		}
	}

	for (int i = 1; i < 10; i++) {	//�Ķ� ���� �ű��
		int yy = By + dy[num] * i;
		int xx = Bx + dx[num] * i;
		if (temp[yy][xx] == 'O') {
			temp[By][Bx] = '.';
			By = 0;
			Bx = 0;
			break;
		}
		else if (temp[yy][xx] != '.') {
			temp[By][Bx] = '.';
			By = By + dy[num] * (i - 1);
			Bx = Bx + dx[num] * (i - 1);
			temp[By][Bx] = 'B';
			break;
		}
	}
}

int main()
{
	cin >> N >> M;

	queue<state> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				map[i][j] = '.';
				Ry = i;
				Rx = j;
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.';
				By = i;
				Bx = j;
			}
		}
	}

	q.push({ Ry,Rx,By,Bx,0 });
	visited[Ry][Rx][By][Bx] = 1;

	while (!q.empty())
	{
		int curRy = q.front().Ry;
		int curRx = q.front().Rx;
		int curBy = q.front().By;
		int curBx = q.front().Bx;
		int cnt = q.front().cnt;
		q.pop();

		if (curRy == 0 && curBy != 0) {		//���� ������ ���� �� cnt���
			cout << cnt;
			return 0;
		}
		else if (curRy == 0 && curBy == 0 || cnt >= 10) {
			continue;						//�� �� ���ų� 10�� �ʰ��̸� continue
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < N; j++) {	//map�迭�� temp�迭�� ����
				for (int k = 0; k < M; k++) {
					temp[j][k] = map[j][k];
				}
			}
			Ry = curRy;
			Rx = curRx;
			By = curBy;
			Bx = curBx;
			temp[Ry][Rx] = 'R';				//������ ��ġ
			temp[By][Bx] = 'B';
			for (int j = 0; j < 2; j++) {	//�Ϻ��ϰ� �����̱� ���ؼ� �ι� ������
				move(i);
			}

			if (visited[Ry][Rx][By][Bx] != 1) {//������ ���� ���°� �־��ٸ� q�� ���� �ʱ�
				visited[Ry][Rx][By][Bx] = 1;
				q.push({ Ry,Rx,By,Bx,cnt + 1 });
			}
		}
	}

	cout << -1;		//10�� �ʰ��߰ų� �׻� �� ������ �� ���� ���
}