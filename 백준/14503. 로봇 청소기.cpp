#include<iostream>

using namespace std;

int arr[55][55];									//��
int N, M;
int cy, cx, dir;
int dy1[4] = { 0,-1,0,1 };							//��ȸ�� ���� �迭
int dx1[4] = { -1,0,1,0 };
int dy2[4] = { 1,0,-1,0 };							//���� ���� �迭
int dx2[4] = { 0,-1,0,1 };
int cnt = 0;

int main()
{
	int result = 0;
	cin >> N >> M;
	cin >> cy >> cx >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1)
	{
		if (arr[cy][cx] == 0) {						//���� �ִ� �ڸ��� û�Ұ� ���� ���� �ڸ��� -1�� �ٲٰ� �ᱣ���� +1
			arr[cy][cx] = -1;
			result++;
		}

		if (cnt == 4) {								//4�� �������� ���� �������� üũ
			int y = cy + dy2[dir];
			int x = cx + dx2[dir];
			if (arr[y][x] == 1) {					//������ �Ұ����ϸ� Ż��
				break;
			}
			else {									//������ �����ϸ� ���� �� cnt �ʱ�ȭ
				cy = y;
				cx = x;
				cnt = 0;
			}
		}

		int yy = cy + dy1[dir];						//��ȸ�� ��ǥ
		int xx = cx + dx1[dir];

		if (arr[yy][xx] == 0) {						//��ȸ�� �� ������ ��ġ�� û�� ���̸� �̵�
			cy = yy;
			cx = xx;
			cnt = 0;
		}
		else {										//�׷��� �ʴٸ� �̵����� �ʰ� cnt++
			cnt++;
		}
		dir -= 1;									//��ȸ��
		if (dir < 0) {
			dir = 3;
		}
	}

	cout << result;
}