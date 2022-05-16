#include <iostream>
#include <queue>

using namespace std;

int N, M;
int x[2], y[2];
char arr[21][21];															//������ ������ ���� ����
char temp[21][21];															//�ݺ��� ������ �ʿ� ������ �߰��ϱ� ���� �迭
int visited[20][20][20][20];												//�湮 ���θ� üũ�� �迭 y1,x1,y2,x2
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y[2];
	int x[2];
	int cnt;
};

int main()
{
	cin >> N >> M;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				arr[i][j] = '.';											//������ ������ ���� �����ϱ� ���� ���� 'o'��� '.'�� ����
				y[cnt] = i;
				x[cnt] = j;
				cnt++;
			}
		}
	}

	queue<pos> q;
	q.push({ {y[0], y[1]}, {x[0], x[1]}, 0 });								//������ ��ǥ�� q�� �ֱ�
	visited[y[0]][x[0]][y[1]][x[1]] = 1;

	while (!q.empty())
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		int out;
		int y1 = q.front().y[0];
		int x1 = q.front().x[0];
		int y2 = q.front().y[1];
		int x2 = q.front().x[1];
		int cnt = q.front().cnt;
		temp[y1][x1] = 'o';
		temp[y2][x2] = 'o';
		q.pop();

		if (cnt == 10) continue;											//��ư�� 10�� �Ѱ� �������� continue

		for (int i = 0; i < 4; i++) {
			out = 0;
			int yy1 = y1 + dy[i];											//����1�� ��ǥ
			int xx1 = x1 + dx[i];
			int yy2 = y2 + dy[i];											//����2�� ��ǥ
			int xx2 = x2 + dx[i];
			if (yy1 >= N || yy1 < 0 || xx1 >= M || xx1 < 0) {				//������ ������ out++
				out++;
			}
			if (yy2 >= N || yy2 < 0 || xx2 >= M || xx2 < 0) {
				out++;
			}
			if (out == 1) {													//�ϳ��� �����ٸ�
				cout << cnt + 1;
				return 0;
			}
			else if (out == 0) {											//�ϳ��� ������ �ʾҴٸ�
				if (arr[yy1][xx1] == '#') {									//������ ��ġ�� ���̸� ����ġ
					yy1 = y1;
					xx1 = x1;
				}
				if (arr[yy2][xx2] == '#') {
					yy2 = y2;
					xx2 = x2;
				}
				if (yy1 == yy2 && xx1 == xx2) continue;						//���� ��ǥ�� �ѹ��̶� �ִٸ� ������ �� �� ���� �������Ƿ� continue
				if (visited[yy1][xx1][yy2][xx2] == 0) {						//�� ���¿��� ���� ���ٸ�
					visited[yy1][xx1][yy2][xx2] = 1;
					q.push({ {yy1,yy2}, {xx1,xx2}, cnt + 1 });
				}
			}
		}
	}

	cout << -1;
}