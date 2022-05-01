#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[110][110];
int temp[110][110];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

void bfs(int y, int x)													//�̾��� ���� üũ�ϴ� bfs �Լ�
{
	int visited[110][110] = { 0 };
	queue<pos> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		if (visited[curY][curX] == 1) continue;							//�湮�ߴ� ���̸� continue
		visited[curY][curX] = 1;										//�湮�� ������ 1�� ��ȯ

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1 && temp[yy][xx] > 0) {			//������ �ϴ� ���� �湮���� �ʾҰų� ���� ����� �ʾ����� q�� �ֱ�
					temp[yy][xx] = -1;									//�鸥 ���̸� -1�� �ʱ�ȭ
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	int height = 0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {									//���� ���� ���츮�� height�� ����
			cin >> arr[i][j];
			if (height < arr[i][j]) {
				height = arr[i][j];
			}
		}
	}

	for (int h = 0; h < height; h++) {									//���̰� 0�� ���츮���� height-1�� ���츮���� ���������� ���� ��׸鼭 üũ
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {								//���̰� h���� ������ ���� ��װ� 0���� ǥ��
				if (arr[i][j] <= h) {
					arr[i][j] = 0;
				}
				temp[i][j] = arr[i][j];									//temp�迭�� �ٽ� ����
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {								//���� �湮���� ���� ������ �鸮�鼭 bfs�� üũ
				if (temp[i][j] > 0) {
					result++;
					bfs(i, j);
				}
			}
		}
		if (max < result) {												//���� ���� ���� ���� max�� ����
			max = result;
		}
	}

	cout << max;
}