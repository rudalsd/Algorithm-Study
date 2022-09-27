#include<iostream>

using namespace std;

struct shark {		//상어의 상태
	int y;
	int x;
	int dir;
};

struct smell {		//냄새 주인과 남은 시간
	int num;
	int k;
};

int N, M, k;
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };
int arr[20][20];
int priority[401][5][4];
smell map[20][20];
shark pos[401];

void move()		//상어 움직임
{
	for (int i = 1; i <= M; i++) {
		bool flag = false;
		if (pos[i].y != -1) {
			for (int j = 0; j < 4; j++) {
				int dir = priority[i][pos[i].dir][j];
				int yy = pos[i].y + dy[dir];
				int xx = pos[i].x + dx[dir];
				if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
					if (map[yy][xx].num == 0) {	//냄새가 없는 장소가 있다면
						arr[pos[i].y][pos[i].x] = 0;
						if (arr[yy][xx] == 0) {	//그 장소에 아무도 없다면
							pos[i] = { yy,xx,dir };
							arr[yy][xx] = i;
						}
						else if (arr[yy][xx] < i) {	//그 장소에 나보다 센 상어가 있다면
							pos[i] = { -1,-1,-1 };
						}
						else if (arr[yy][xx] > i) {	//그 장소에 나보다 약한 상어가 있다면
							pos[arr[yy][xx]] = { -1,-1,-1 };
							pos[i] = { yy,xx,dir };
							arr[yy][xx] = i;
						}
						flag = true;
						break;
					}
				}
			}
			if (flag == false) {	//냄새가 모두 둘러싸고 있다면
				for (int j = 0; j < 4; j++) {
					int dir = priority[i][pos[i].dir][j];
					int yy = pos[i].y + dy[dir];
					int xx = pos[i].x + dx[dir];
					if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
						if (map[yy][xx].num == i) {	//나의 냄새가 있는 곳으로
							arr[pos[i].y][pos[i].x] = 0;
							pos[i] = { yy,xx,dir };
							arr[yy][xx] = i;
							break;
						}
					}
				}
			}
		}
	}
}

void smells()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].num != 0) {
				map[i][j].k--;
				if (map[i][j].k == 0) {
					map[i][j].num = 0;
				}
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (pos[i].y != -1) {
			map[pos[i].y][pos[i].x] = { i, k };
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &k);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			pos[arr[i][j]] = { i,j };
		}
	}

	for (int i = 1; i <= M; i++) {
		int dir;
		scanf("%d", &dir);

		pos[i].dir = dir;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				int dir;
				scanf("%d", &dir);

				priority[i][j][k] = dir;
			}
		}
	}

	int ans = 0;

	while (1) {
		ans++;
		smells();

		move();

		int cnt = 0;

		for (int i = 1; i <= M; i++) {
			if (pos[i].y != -1) {
				cnt++;
			}
		}

		if (cnt == 1) {	//1번 상어만 남는다면
			printf("%d", ans);
			return 0;
		}

		if (ans == 1000) {	//1000번을 넘으면
			printf("%d", -1);
			return 0;
		}
	}
}