#include<iostream>
#include<queue>

using namespace std;

int N, M, T;
int arr[101][101];
int visited[101][101][2];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int cnt;
	int gram;
};

int main()
{
	scanf("%d %d %d", &N, &M, &T);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	queue<node> q;
	q.push({ 1,1,0,false });
	visited[1][1][0] = 1;

	while (!q.empty()) {
		const int y = q.front().y;
		const int x = q.front().x;
		const int cnt = q.front().cnt;
		const int gram = q.front().gram;
		q.pop();

		if (cnt > T) continue;

		if (y == N && x == M) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy > 0 && yy <= N && xx > 0 && xx <= M) {
				if ((arr[yy][xx] == 1 && gram == true) || arr[yy][xx] == 0) {
					if (visited[yy][xx][gram] != 1) {
						visited[yy][xx][gram] = 1;
						q.push({ yy,xx,cnt + 1,gram });
					}
				}
				else if (arr[yy][xx] == 2) {
					if (visited[yy][xx][1] != 1) {
						visited[yy][xx][1] = 1;
						q.push({ yy,xx,cnt + 1,1 });
					}
				}

			}
		}
	}

	printf("Fail");
}