#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int arr[110][110];				//������
int visited[110][110];			//�湮 ����
int dy[4] = { -1,1,0,0 };		//���� �迭
int dx[4] = { 0,0,-1,1 };
vector<int> area;				//���� ����

struct pos {
	int y;
	int x;
};

int bfs(int y, int x)			//���� ���ϱ� ���� bfs
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

	for (int k = 0; k < K; k++) {				//���簢�� ���� ��ġ�� 1�� �ʱ�ȭ
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
				area.push_back(bfs(i, j));		//�����̿� 1�� �ƴ� ������ bfs�� ������ ���� push
			}
		}
	}

	sort(area.begin(), area.end());				//������������ sort

	cout << area.size() << endl;
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}
}