#include<iostream>
#include<vector>

using namespace std;

struct fish {
	int y;
	int x;
	int d;
};

int M, S;
int arr[5][5];	//상어 위치
int smell[5][5];	//냄새 위치
vector<fish> vect;
int fy[9] = { 0,0,-1,-1,-1,0,1,1,1 };	//물고기 방향 배열
int fx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[4] = { -1,0,1,0 };		//상어 방향 배열
int dx[4] = { 0,-1,0,1 };
int cnt[5][5];	//물고기 수
int sy, sx;		//상어 좌표
pair<int, int> temp[3];
pair<int, int> box[3];
int Max;

void dfs(int y, int x, int level, int ans)	//상어 이동
{
	if (level == 3) {
		if (Max < ans) {
			Max = ans;
			for (int i = 0; i < 3; i++) {
				box[i] = temp[i];
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy > 0 && yy <= 4 && xx > 0 && xx <= 4) {
			temp[level] = { yy,xx };
			int temp = cnt[yy][xx];
			cnt[yy][xx] = 0;
			dfs(yy, xx, level + 1, ans + temp);
			cnt[yy][xx] = temp;
		}
	}
}

void move()		//물고기 이동
{
	for (auto& next : vect) {
		int y = next.y;
		int x = next.x;
		int d = next.d;
		for (int i = 0; i < 8; i++) {
			int yy = y + fy[d];
			int xx = x + fx[d];
			if (yy > 0 && yy <= 4 && xx > 0 && xx <= 4) {
				if (arr[yy][xx] == 0 && smell[yy][xx] == 0) {
					next.y = yy;
					next.x = xx;
					next.d = d;
					cnt[y][x]--;
					cnt[yy][xx]++;
					break;
				}
			}
			d--;
			if (d <= 0) {
				d += 8;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &M, &S);

	for (int i = 0; i < M; i++) {
		int y, x, d;
		scanf("%d %d %d", &y, &x, &d);
		vect.push_back({ y,x,d });
		cnt[y][x]++;
	}

	scanf("%d %d", &sy, &sx);

	arr[sy][sx] = 5;

	for (int s = 0; s < S; s++) {
		vector<fish> temp = vect;

		move();

		Max = -1;

		dfs(sy, sx, 0, 0);
		arr[sy][sx] = 0;
		sy = box[2].first;
		sx = box[2].second;
		arr[sy][sx] = 5;

		for (int i = 0; i < 3; i++) {
			cnt[box[i].first][box[i].second] = 0;
		}

		for (int i = 0; i < vect.size(); i++) {
			for (int j = 0; j < 3; j++) {
				if (vect[i].y == box[j].first && vect[i].x == box[j].second) {
					smell[vect[i].y][vect[i].x] = 3;
					cnt[vect[i].y][vect[i].x] = 0;
					vect[i].y = 0;
					break;
				}
			}
		}

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (smell[i][j] > 0) {
					smell[i][j]--;
				}
			}
		}

		for (int i = 0; i < temp.size(); i++) {
			cnt[temp[i].y][temp[i].x]++;
		}

		for (int i = 0; i < vect.size(); i++) {
			if (vect[i].y != 0) {
				temp.push_back({ vect[i].y, vect[i].x, vect[i].d });
			}
		}

		vect = temp;
	}

	printf("%d", vect.size());
}