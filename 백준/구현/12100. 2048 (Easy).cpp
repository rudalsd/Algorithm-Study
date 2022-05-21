#include <iostream>

using namespace std;

int N;
int arr[21][21];
int ans = 0;

void move()																//������ ��ġ�� �ű�� �Լ�
{
	for (int i = 0; i < N; i++) {
		int before = 0;
		int y;
		int x;
		for (int j = 0; j < N; j++) {
			if (before == 0) {
				if (arr[i][j] != 0) {
					before = arr[i][j];
					y = i;
					x = j;
				}
			}
			else {
				if (arr[i][j] != 0) {
					if (before == arr[i][j]) {
						arr[y][x] = before * 2;
						arr[i][j] = 0;
						before = 0;
					}
					else {
						before = arr[i][j];
						y = i;
						x = j;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0) {
				if (cnt != j) {
					arr[i][cnt] = arr[i][j];
					arr[i][j] = 0;
				}
				cnt++;
			}
		}
	}
}

void turn(int num)														//num��ŭ 90�� ȸ��
{
	int temp[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int k = 0; k < num; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = temp[j][N - i - 1];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = arr[i][j];
			}
		}
	}
}

void dfs(int level)
{
	if (level == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] > ans) {
					ans = arr[i][j];
				}
			}
		}
		return;
	}

	int temp[21][21];													//��Ʈ��ŷ�� ���� temp�迭 ����

	for (int i = 0; i < N; i++) {										//���� ����� temp�� ����
		for (int j = 0; j < N; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int k = 0; k < 4; k++) {
		turn(k);
		move();															//�ű� ��
		dfs(level + 1);													//�������� �Ѿ�ٰ�
		for (int i = 0; i < N; i++) {									//���� �� ���� ����
			for (int j = 0; j < N; j++) {
				arr[i][j] = temp[i][j];
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0);

	cout << ans;
}