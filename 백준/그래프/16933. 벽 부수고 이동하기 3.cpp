#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int y;		//yÁÂÇ¥
	int x;		//xÁÂÇ¥
	int cnt;	//ÀÌµ¿ °Å¸®
	int crash;	//ºÎ¼ø º® °³¼ö
	int day;	//0 : ¹ã, 1 : ³·
};

int N, M, K;
char arr[1002][1002];
int visited[1001][1001][11][2];		//visited[y][x][crash][day]
const int dy[5] = { 0,-1,1,0,0 };
const int dx[5] = { 0,0,0,-1,1 };

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%s", &arr[i][1]);
	}

	queue<pos> q;

	q.push({ 1,1,1,0,1 });
	visited[1][1][0][1] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		const int crash = q.front().crash;
		const int day = q.front().day;
		q.pop();

		if (y == N && x == M) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 5; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy > 0 && yy <= N && xx > 0 && xx <= M) {
				if (day == 0) {	//¹ãÀÏ ¶§
					if (i == 0) {
						if (arr[yy][xx] == '1' && visited[yy][xx][crash][1] != 1) {
							visited[yy][xx][crash][1] = 1;
							q.push({ yy,xx,cnt + 1,crash,1 });
						}
					}
					if (arr[yy][xx] == '0' && visited[yy][xx][crash][1] != 1) {
						visited[yy][xx][crash][1] = 1;
						q.push({ yy,xx,cnt + 1,crash,1 });
					}
				}
				else {	//³·ÀÏ ¶§
					if (i != 0) {
						if (arr[yy][xx] == '0' && visited[yy][xx][crash][0] != 1) {
							visited[yy][xx][crash][0] = 1;
							q.push({ yy,xx,cnt + 1,crash,0 });
						}
						else if (arr[yy][xx] == '1' && crash < K) {
							if (visited[yy][xx][crash + 1][0] != 1) {
								visited[yy][xx][crash + 1][0] = 1;
								q.push({ yy,xx,cnt + 1,crash + 1,0 });
							}
						}
					}
				}
			}
		}
	}

	printf("%d", -1);
}