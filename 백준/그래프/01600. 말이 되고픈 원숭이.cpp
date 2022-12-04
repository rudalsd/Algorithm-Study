#include<iostream>
#include<queue>

using namespace std;

int K, W, H;
int arr[200][200];
int visited[200][200][31];
int dy[4] = { -1,1,0,0 };	//인접
int dx[4] = { 0,0,-1,1 };
int dyy[8] = { -2,-1,1,2,2,1,-1,-2 };	//말처럼
int dxx[8] = { 1,2,2,1,-1,-2,-2,-1 };

struct node {
	int y;
	int x;
	int k;
	int cnt;
};

int main()
{
	scanf("%d %d %d", &K, &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	queue<node> q;

	q.push({ 0,0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int k = q.front().k;
		const int cnt = q.front().cnt;
		q.pop();

		if (y == H - 1 && x == W - 1) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < H && xx >= 0 && xx < W) {	// 인접한 곳으로 이동
				if (visited[yy][xx][k] != 1 && arr[yy][xx] == 0) {
					visited[yy][xx][k] = 1;
					q.push({ yy,xx,k,cnt + 1 });
				}
			}
		}

		if (k < K) {
			for (int i = 0; i < 8; i++) {	//말처럼 이동
				const int yy = y + dyy[i];
				const int xx = x + dxx[i];

				if (yy >= 0 && yy < H && xx >= 0 && xx < W) {
					if (visited[yy][xx][k + 1] != 1 && arr[yy][xx] == 0) {
						visited[yy][xx][k + 1] = 1;
						q.push({ yy,xx,k + 1,cnt + 1 });
					}
				}
			}
		}
	}

	printf("%d", -1);
}