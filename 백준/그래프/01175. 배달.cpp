#include<iostream>
#include<queue>

using namespace std;

int N, M;
int visited[50][50][4][4];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
char arr[51][51];

struct node {
	int y;
	int x;
	int dir;
	int del;
	int cnt;
};

int main()
{
	scanf("%d %d", &N, &M);
	queue<node> q;

	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'S') {
				q.push({ i,j,-1,0,0 });
				visited[i][j][0][0] = 1;
				visited[i][j][1][0] = 1;
				visited[i][j][2][0] = 1;
				visited[i][j][3][0] = 1;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'C') {
				arr[i][j] = '0' + cnt++;
			}
		}
	}

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int dir = q.front().dir;
		const int del = q.front().del;
		const int cnt = q.front().cnt;
		q.pop();

		if (del == 3) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			if (i != dir) {
				const int yy = y + dy[i];
				const int xx = x + dx[i];

				if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
					if (arr[yy][xx] == '.' && visited[yy][xx][i][del] == 0) {
						visited[yy][xx][i][del] = 1;
						q.push({ yy,xx,i,del,cnt + 1 });
					}
					else if (arr[yy][xx] >= '0' && arr[yy][xx] < '2') {
						const int temp = del | (1 << arr[yy][xx] - '0');
						if (visited[yy][xx][i][temp] == 0) {
							visited[yy][xx][i][temp] = 1;
							q.push({ yy,xx,i,temp,cnt + 1});
						}
					}
				}
			}
		}
	}

	printf("-1");
}