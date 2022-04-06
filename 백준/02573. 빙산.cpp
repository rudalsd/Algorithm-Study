#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct pos {
	int y;
	int x;
};

int arr[300][300];										//������ ��Ÿ���� �迭
int temp[300][300];										//������ ������ ���¸� �����ϴ� �迭
int visited[300][300];
int N, M;
int dy[4] = { -1,1,0,0 };								//����迭
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x)									//bfs�� ���� �̾��� ������ -1�� ����
{
	memset(visited, 0, sizeof(visited));
	queue<pos> q;
	q.push({ y, x });
	temp[y][x] = -1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		if (visited[curY][curX] == 1) continue;
		visited[curY][curX] = 1;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (temp[yy][xx] != 0) {
				q.push({ yy,xx });
				temp[yy][xx] = -1;
			}
		}
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {							//�� �Է�
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int year = 0;											//�޼� �ʱ�ȭ

	while (1)
	{
		for (int i = 0; i < N; i++) {						//temp�迭�� ������ ���� ���� ����
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] > 0) {						//���� 0���� Ŭ �� bfs ������
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {										//������ �ѹ��� ��Ƴ����� ��
			cout << 0;
			return 0;
		}
		else if (cnt > 1) {									//������ 2���� �̻����� ���������� ��
			cout << year;
			return 0;
		}

		year++;												//�޼�+1

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						int yy = i + dy[k];
						int xx = j + dx[k];
						if (temp[yy][xx] == 0) {			//�ٴ幰�� ��� �ִ� ��ŭ arr�迭 �� -1
							arr[i][j] -= 1;
						}
					}
				}
				if (arr[i][j] < 0) {						//arr�迭�� ���� 0���� ������ 0���� ����
					arr[i][j] = 0;
				}
			}
		}
	}
}