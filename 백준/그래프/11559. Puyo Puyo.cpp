#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char arr[12][7];
char temp[12][7];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

char cnt = '0';

struct pos {
	int y;
	int x;
};

int bfs(int y, int x)															//�پ� �ִ� �ѿ��� ������ ���� bfs
{
	queue<pos> q;

	q.push({ y,x });
	temp[y][x] = cnt;
	int ans = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < 12 && xx >= 0 && xx < 6) {
				if (arr[y][x] == arr[yy][xx] && temp[yy][xx] != cnt) {
					q.push({ yy,xx });
					ans++;														//�پ��ִ� �ѿ䰡 ���� ������ ans++
					temp[yy][xx] = cnt;
				}
			}
		}
	}

	return ans;
}

void set()																		//�ѿ並 �νð� �Ʒ��� ����Ʈ���� �Լ�
{
	for (int i = 0; i < 6; i++) {
		int a = 11;
		for (int j = 11; j >= 0; j--) {
			if (arr[j][i] != '.') {
				if (a != j) {
					arr[a][i] = arr[j][i];
					arr[j][i] = '.';
				}
				a--;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 12; i++) {
		cin >> arr[i];
	}

	int ans = 0;

	while (1)
	{
		int flag = 0;
		cnt = '0';
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (temp[i][j] >= 'A' && temp[i][j] <= 'Z') {
					if (bfs(i, j) >= 4) {										//�پ� �ִ� �ѿ��� ���� 4�� �̻��̶��
						flag = 1;												//��ȭ�� �ִٰ� ǥ��
						for (int a = 0; a < 12; a++) {							//���� �� ���鼭
							for (int b = 0; b < 6; b++) {
								if (temp[a][b] == cnt) {						//��� ���� ���̸�
									arr[a][b] = '.';							//arr�迭�� '.'�� �ٲ���
								}
							}
						}
					}
					cnt++;
				}
			}
		}

		if (flag == 0) {														//��ȭ�� ���ٸ� ���� Ż��
			break;
		}
		else {																	//��ȭ�� �ִٸ� �� ����
			set();
		}
		ans++;
	}

	cout << ans;
}