#include<iostream>

using namespace std;

int N;
int arr[500][500];
int ans;
int x;
int y;
int dx[4][9] = {	//각 방향별로 방향 배열을 설정
	1,1,0,0,0,0,-1,-1,-2,	//좌
	-1,-1,0,0,0,0,1,1,2,	//우
	-1,1,-2,2,-1,1,-1,1,0,	//위
	-1,1,-2,2,-1,1,-1,1,0,	//아래
};
int dy[4][9] = {
	-1,1,-2,2,-1,1,-1,1,0,	//좌
	-1,1,-2,2,-1,1,-1,1,0,	//우
	1,1,0,0,0,0,-1,-1,-2,	//위
	-1,-1,0,0,0,0,1,1,2,	//아래
};

int ddy[4] = { 0,0,-1,1 };
int ddx[4] = { -1,1,0,0 };

void direction(int y, int x, int dir)
{
	int ret = 0;

	x = x + ddx[dir];
	y = y + ddy[dir];

	int out = 0;
	int move = 0;
	int tornado = 0;

	for (int i = 0; i < 9; i++) {	//모래의 이동 기록
		int yy = y + dy[dir][i];
		int xx = x + dx[dir][i];
		int temp = 0;
		if (i < 2) {
			temp = arr[y][x] / 100;
		}
		else if (i < 4) {
			temp = arr[y][x] / 50;
		}
		else if (i < 6) {
			temp = (arr[y][x] * 7) / 100;
		}
		else if (i < 8) {
			temp = arr[y][x] / 10;
		}
		else {
			temp = arr[y][x] / 20;
		}

		if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
			arr[yy][xx] += temp;
			tornado += temp;
		}
		else {
			tornado += temp;
			out += temp;
		}
	}

	move = arr[y][x] - tornado;	//알파 칸으로 움직일 모래의 양
	arr[y][x] = 0;
	ans += out;		//경계 밖으로 나간 모래의 양

	int yy = y + ddy[dir];
	int xx = x + ddx[dir];
	if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
		arr[yy][xx] += move;	//알파 칸이 경계 밖이 아니라면
	}
	else {						//밖이라면
		ans += move;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	x = y = N / 2;

	for (int i = 1; i <= N; i++) {	//토네이도 이동
		if (y == 0 && x == 0) {
			break;
		}
		if (i % 2 == 0) {
			for (int j = 0; j < i; j++) {
				direction(y, x, 1);
				x += 1;
			}
			for (int j = 0; j < i; j++) {
				direction(y, x, 2);
				y -= 1;
			}
		}
		else {
			for (int j = 0; j < i; j++) {
				if (y == 0 && x == 0) {
					break;
				}
				direction(y, x, 0);
				x -= 1;
			}
			if (y == 0 && x == 0) {
				break;
			}
			for (int j = 0; j < i; j++) {
				direction(y, x, 3);
				y += 1;
			}
		}
	}

	printf("%d", ans);
}