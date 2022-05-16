#include<iostream>

using namespace std;

int dy[4] = { -1,1,0,0 };									//����迭
int dx[4] = { 0,0,-1,1 };
char arr[1000][1000];										//����
int visited[1000][1000];									//�湮 ���� üũ �迭
int N, M;
char dir[5] = "UDLR";
int cnt;

struct pos {
	int y;
	int x;
};

void dfs(int y, int x)										//�湮�� �� visited �迭�� ���
{
	visited[y][x] = 1;
	int yy, xx;
	for (int i = 0; i < 4; i++) {
		if (arr[y][x] == dir[i]) {
			yy = y + dy[i];
			xx = x + dx[i];

			if (visited[yy][xx] == 1) {						//ó�� ������� ����Ŭ�̸� cnt++
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
			if (visited[i][j] == 0) {						//�湮���� ���� ���� ���� bfs ������
				dfs(i, j);
			}
		}
	}

	cout << cnt;
}