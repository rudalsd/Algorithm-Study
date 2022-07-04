#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[8][8];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int ans;

struct pos {
	int y;
	int x;
};

int bfs(int map[][8])		//���̷����� ��Ʈ�� �� ���� ������ ũ�⸦ ���
{
	queue<pos>q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (map[yy][xx] == 0) {
					map[yy][xx] = 2;
					q.push({ yy,xx });
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void dfs(int level, int num)		//���� ����� ���� ����Լ�
{
	if (level == 3) {			//���� 3�����
		int temp[8][8] = { 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		int cnt = bfs(temp);

		if (ans < cnt) {
			ans = cnt;
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (N * i + j > num) {		//������ ���� ���� �� �������� Ž��
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					dfs(level + 1, i * N + j);
					arr[i][j] = 0;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, -1);

	cout << ans;
}