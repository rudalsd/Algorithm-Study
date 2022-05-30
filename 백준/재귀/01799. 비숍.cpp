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

int check(int y, int x)		//비숍을 놓을 수 있으면 1 리턴 없으면 0 리턴
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

void dfsW(int y, int x)		//체스판의 흰색 부분
{
	int flag = 0;
	while ((arr[y][x].num != 1 || arr[y][x].color != 0) && y < N) {
		x++;				//체스말을 놓을 수 있을 때 까지 x++
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

	if (check(y, x)) {		//비숍을 놓을 수 있는지 없는지 체크 후
		arr[y][x].num = 2;	//말을 놓거나
	}
	else {
		flag = 1;			//놓지 못한다고 체크
	}

	int nx = x + 1;
	int ny = y;
	if (nx == N) {
		nx = 0;
		ny++;
	}
	dfsW(ny, nx);

	if (flag != 1) {		//비숍을 놓은 상황이라면
		arr[y][x].num = 1;	//원상복구
	}
	else {
		return;				//아니라면 같은 상황을 겪게 되므로 return
	}

	dfsW(ny, nx);
}

void dfsB(int y, int x)		//체스판의 검은색 부분
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
			if (i % 2 == 0) {		//체스판의 검은색 부분을 1로 경신
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