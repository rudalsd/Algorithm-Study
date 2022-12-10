#include<iostream>
#include<queue>

using namespace std;

struct robot {
	int y;
	int x;
	int dir;
	int cnt;
};

int N, M;
int arr[101][101];
int visited[101][101][5];
int dy[5] = { 0,0,0,1,-1 };
int dx[5] = { 0,1,-1,0,0 };
int ans = 987654321;

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			for (int k = 1; k <= 4; k++) {
				visited[i][j][k] = 987654321;
			}
		}
	}

	robot start, end;

	scanf("%d %d %d", &start.y, &start.x, &start.dir);
	scanf("%d %d %d", &end.y, &end.x, &end.dir);

	queue<robot> q;

	q.push({ start.y, start.x, start.dir, 0 });

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int dir = q.front().dir;
		int cnt = q.front().cnt;
		q.pop();

		if (y == end.y && x == end.x) {
			if (dir != end.dir) {
				if (dir == 1 || dir == 2) {
					if (end.dir == 3 || end.dir == 4) {
						cnt += 1;
					}
					else {
						cnt += 2;
					}
				}
				else {
					if (end.dir == 1 || end.dir == 2) {
						cnt += 1;
					}
					else {
						cnt += 2;
					}
				}
			}

			ans = min(ans, cnt);
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 3; j++) {
				int temp = dir + i;
				if (temp > 4) {
					temp -= 4;
				}
				int yy = y + dy[temp] * j;
				int xx = x + dx[temp] * j;

				if (yy > 0 && yy <= M && xx > 0 && xx <= N) {
					if (arr[yy][xx] == 0) {
						if (i == 0) {
							if (visited[yy][xx][temp] > cnt + 1) {
								visited[yy][xx][temp] = cnt + 1;
								q.push({ yy,xx,temp,cnt + 1 });
							}
						}
						else {
							if (dir == 1 || dir == 3) {
								if (i == 1) {
									if (visited[yy][xx][temp] > cnt + 3) {
										visited[yy][xx][temp] = cnt + 3;
										q.push({ yy,xx,temp,cnt + 3 });
									}
								}
								else if (i == 2 || i == 3) {
									if (visited[yy][xx][temp] > cnt + 2) {
										visited[yy][xx][temp] = cnt + 2;
										q.push({ yy,xx,temp,cnt + 2 });
									}
								}
							}
							else {
								if (i == 3) {
									if (visited[yy][xx][temp] > cnt + 3) {
										visited[yy][xx][temp] = cnt + 3;
										q.push({ yy,xx,temp,cnt + 3 });
									}
								}
								else if (i == 1 || i == 2) {
									if (visited[yy][xx][temp] > cnt + 2) {
										visited[yy][xx][temp] = cnt + 2;
										q.push({ yy,xx,temp,cnt + 2 });
									}
								}
							}
						}
					}
					else break;
				}
				else break;
			}
		}
	}

	printf("%d", ans);
}