#include<iostream>

using namespace std;

int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };

struct fish {
	int y;
	int x;
	int dir;
};

int arr[4][4];
fish pos[18];
int ans;

void move()		//물고기 이동
{
	for (int i = 1; i <= 16; i++) {
		if (pos[i].y != -1) {
			int y = pos[i].y;
			int x = pos[i].x;
			int dir = pos[i].dir;
			for (int j = 0; j < 8; j++) {
				int yy = y + dy[dir];
				int xx = x + dx[dir];
				if (yy >= 0 && yy < 4 && xx >= 0 && xx < 4) {
					if (arr[yy][xx] == 0) {	//빈칸일 때
						arr[yy][xx] = arr[y][x];
						arr[y][x] = 0;
						pos[i] = { yy,xx, dir };
						break;
					}
					else if (arr[yy][xx] != 17) {	//상어가 있을 때
						int temp = arr[yy][xx];
						arr[yy][xx] = arr[y][x];
						arr[y][x] = temp;

						pos[arr[yy][xx]] = { yy,xx,dir };
						pos[arr[y][x]].y = y;
						pos[arr[y][x]].x = x;
						break;
					}
					else {	//이동이 불가할 때
						dir++;
					}
				}
				else {	//이동이 불가할 때
					dir++;
				}
				if (dir > 8) {
					dir = 1;
				}
			}
		}
	}
}

void dfs(int cnt)
{
	ans = max(ans, cnt);	//먹은 물고기 번호의 합

	move();

	int temp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	fish tempPos[18];
	for (int i = 1; i <= 17; i++) {
		tempPos[i] = pos[i];
	}

	int y = pos[17].y;
	int x = pos[17].x;
	int dir = pos[17].dir;
	int tempCnt = cnt;

	for (int i = 1; i < 4; i++) {
		int yy = y + dy[dir] * i;
		int xx = x + dx[dir] * i;
		if (yy >= 0 && yy < 4 && xx >= 0 && xx < 4) {
			if (arr[yy][xx] != 0) {	//물고기를 먹었을 때
				pos[17] = { yy,xx,pos[arr[yy][xx]].dir };
				cnt += arr[yy][xx];
				pos[arr[yy][xx]] = { -1,-1,-1 };
				arr[yy][xx] = 17;
				arr[y][x] = 0;
				dfs(cnt);
				cnt = tempCnt;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						arr[i][j] = temp[i][j];
					}
				}
				for (int i = 1; i <= 17; i++) {
					pos[i] = tempPos[i];
				}
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			scanf("%d %d", &num, &dir);

			arr[i][j] = num;
			pos[num] = { i,j,dir };
		}
	}

	pos[17] = { 0,0, pos[arr[0][0]].dir };	//처음 0, 0에서 물고기를 먹었을 때
	pos[arr[0][0]] = { -1,-1,-1 };
	int cnt = arr[0][0];
	arr[0][0] = 17;

	dfs(cnt);

	printf("%d", ans);
}