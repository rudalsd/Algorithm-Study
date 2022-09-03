#include<iostream>
#include<cmath>

using namespace std;

int N;
int arr[401][4];
int order[401];
int map[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int like(int y, int x, int cur)	//주변 좋아하는 학생 수 체크
{
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
			for (int j = 0; j < 4; j++) {
				if (map[yy][xx] == arr[cur][j]) {
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int space(int y, int x)		//주변 빈 자리 수 체크
{
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
			for (int j = 0; j < 4; j++) {
				if (map[yy][xx] == 0) {
					cnt++;
				}
			}
		}
	}

	return cnt;
}

void seat(int cur)	//자리 정하기
{
	int y;
	int x;
	int spaceCnt = -1;	//0이 최솟값이므로 -1로 초기화
	int likeCnt = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) {
				int tempLike = like(i, j, cur);
				int tempSpace = space(i, j);
				if (likeCnt < tempLike) {
					likeCnt = tempLike;
					spaceCnt = tempSpace;
					y = i;
					x = j;
				}
				else if (likeCnt == tempLike) {
					if (spaceCnt < tempSpace) {
						spaceCnt = tempSpace;
						y = i;
						x = j;
					}
				}
			}
		}
	}

	map[y][x] = cur;
}

int ans()	//점수 구하기
{
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = like(i, j, map[i][j]);
			if (cnt > 0) {
				ret += pow(10, cnt - 1);
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N * N; i++) {
		int n;
		scanf("%d", &n);
		order[i] = n;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &arr[n][j]);
		}
	}

	for (int i = 1; i <= N * N; i++) {
		seat(order[i]);
	}

	printf("%d", ans());
}