#include <iostream>

using namespace std;

char arr[10][10];

int garo[10][10];													//���� ĭ�� ���ڸ� ������ �迭
int sero[10][10];													//���� ĭ�� ���ڸ� ������ �迭
int nemo[10][10];													//3x3¥�� �簢�� ĭ�� ���ڸ� ������ �迭

int cnt = 0;

struct pos {
	int y;
	int x;
};

pos node[100];														//����� �ִ� ĭ�� ��ǥ�� ������ �迭
int result;

void dfs(int level)
{
	if (result == 1) {												//����� ������ return
		return;
	}
	if (level == cnt) {												//�ѹ� �� ä������ result = 1�� �ٲٰ� arr�迭 ���
		result = 1;
		for (int i = 0; i < 9; i++) {
			cout << arr[i] << endl;
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int yy = node[level].y;										//���� �� ĭ�� �ѹ��� ������ ���� ���ڸ� �ֱ�
		int xx = node[level].x;
		if (sero[xx][i] != 1 && garo[yy][i] != 1 && nemo[(yy / 3) * 3 + xx / 3][i] != 1) {
			sero[xx][i] = 1;
			garo[yy][i] = 1;
			nemo[(yy / 3) * 3 + xx / 3][i] = 1;
			arr[yy][xx] = i + '0';
			dfs(level + 1);
			arr[yy][xx] = '0';
			sero[xx][i] = 0;
			garo[yy][i] = 0;
			nemo[(yy / 3) * 3 + xx / 3][i] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] == '0') {
				node[cnt] = { i,j };								//����� �ִ� ĭ�� ��ǥ�� ����
				cnt++;

			}
			else {													//ä���� ���� ��� ������ �迭�� ���� ����
				int num = arr[i][j] - '0';
				garo[i][num]++;
				sero[j][num]++;
				nemo[(i / 3) * 3 + j / 3][num]++;
			}
		}
	}

	dfs(0);															//dfs ����
}