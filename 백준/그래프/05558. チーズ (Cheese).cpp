#include<iostream>
#include<queue>

using namespace std;

int H, W, N;
char arr[1001][1001];
int visited[1001][1001][10];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
	int cheese;
	int cnt;
};

int main()
{
	queue<pos> q;
	scanf("%d %d %d", &H, &W, &N);

	for (int i = 0; i < H; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == 'S') {
				q.push({ i,j,0,0 });
				visited[i][j][0] = 1;
				break;
			}
		}
		if (!q.empty()) break;
	}

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cheese = q.front().cheese;
		const int cnt = q.front().cnt;
		q.pop();

		if (cheese == N) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < H && xx >= 0 && xx < W) {
				if (arr[yy][xx] != 'X') {
					if (arr[yy][xx] == cheese + '0' + 1) {
						if (visited[yy][xx][cheese + 1] != 1) {
							visited[yy][xx][cheese + 1] = 1;
							q.push({ yy,xx,cheese + 1,cnt + 1 });
						}
					}
					else {
						if (visited[yy][xx][cheese] != 1) {
							visited[yy][xx][cheese] = 1;
							q.push({ yy,xx,cheese,cnt + 1 });
						}
					}
				}
			}
		}
	}
}