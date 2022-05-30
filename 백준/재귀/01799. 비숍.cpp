#include <iostream>

using namespace std;

struct board {
	int num;
	int color = 0;
};

int N;
board arr[11][11];
int dy[4] = { -1,-1,1,1 };
int dx[4] = { -1,1,-1,1 };
int ansW;
int ansB;

int check(int y, int x)		//����� ���� �� ������ 1 ���� ������ 0 ����
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < N; j++) {
			int yy = y + dy[i] * j;
			int xx = x + dx[i] * j;
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (arr[yy][xx].num == 2) {
					return 0;
				}
			}
		}
	}

	return 1;
}

void dfsW(int y, int x)		//ü������ ��� �κ�
{
	int flag = 0;
	while ((arr[y][x].num != 1 || arr[y][x].color != 0) && y < N) {
		x++;				//ü������ ���� �� ���� �� ���� x++
		if (x == N) {
			y++;
			x = 0;
		}
	}

	if (y == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].num == 2) {
					cnt++;
				}
			}
		}
		if (ansW < cnt) {
			ansW = cnt;
		}
		return;
	}

	if (check(y, x)) {		//����� ���� �� �ִ��� ������ üũ ��
		arr[y][x].num = 2;	//���� ���ų�
	}
	else {
		flag = 1;			//���� ���Ѵٰ� üũ
	}

	int nx = x + 1;
	int ny = y;
	if (nx == N) {
		nx = 0;
		ny++;
	}
	dfsW(ny, nx);

	if (flag != 1) {		//����� ���� ��Ȳ�̶��
		arr[y][x].num = 1;	//���󺹱�
	}
	else {
		return;				//�ƴ϶�� ���� ��Ȳ�� �ް� �ǹǷ� return
	}

	dfsW(ny, nx);
}

void dfsB(int y, int x)		//ü������ ������ �κ�
{
	int flag = 0;
	while ((arr[y][x].num != 1 || arr[y][x].color != 1) && y < N) {
		x++;
		if (x == N) {
			y++;
			x = 0;
		}
	}

	if (y == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j].num == 2) {
					cnt++;
				}
			}
		}
		if (ansB < cnt) {
			ansB = cnt;
		}
		return;
	}

	if (check(y, x)) {
		arr[y][x].num = 2;
	}
	else {
		flag = 1;
	}

	int nx = x + 1;
	int ny = y;
	if (nx == N) {
		nx = 0;
		ny++;
	}
	dfsB(ny, nx);

	if (flag != 1) {
		arr[y][x].num = 1;
	}
	else {
		return;
	}

	dfsB(ny, nx);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j].num;
			if (i % 2 == 0) {		//ü������ ������ �κ��� 1�� ���
				if (j % 2 == 1) {
					arr[i][j].color = 1;
				}
			}
			else {
				if (j % 2 == 0) {
					arr[i][j].color = 1;
				}
			}
		}
	}

	dfsW(0, 0);
	dfsB(0, 1);

	cout << ansW + ansB;
}