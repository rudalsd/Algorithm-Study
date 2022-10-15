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

void bfs(int y, int x)		//ġ� �ѷ��׿� ���� ���� ������ 2�� �ʱ�ȭ
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

int check()		//ġ� �� ��Ҵ��� üũ�ϴ� �Լ�
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

int Cnt(int y, int x)	//�ǳ� �µ��� ���� �� Ƚ���� ���
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

	while (!check())		//ġ� �� ���� ������
	{
		bfs(0, 0);		//0, 0���� 2�� �� ���� 2�� �ʱ�ȭ

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {	//2ĭ �̻� ����ִٸ� ����
					if (Cnt(i, j) >= 2) {
						map[i][j] = 0;
					}
				}
			}
		}

		cnt++;		//Ƚ�� �߰�
	}

	cout << cnt;
}