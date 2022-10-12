#include<iostream>
#include<queue>

using namespace std;

int N, M, K;
char arr[1000][1001];
int visited[1000][1000][10];	//부순 벽의 개수에 따라 방문을 다르게 해줌
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
	int cnt;
	int cntW;
};

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	queue<pos> q;
	q.push({ 0,0,1,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int cntW = q.front().cntW;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			printf("%d", cnt);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '0' && visited[yy][xx][cntW] != 1) {	//벽이 아닐 때
					visited[yy][xx][cntW] = 1;
					q.push({ yy,xx,cnt + 1,cntW });
				}
				else if (arr[yy][xx] == '1' && visited[yy][xx][cntW + 1] != 1 && cntW < K) {	//벽일 때
					visited[yy][xx][cntW + 1] = 1;
					q.push({ yy,xx,cnt + 1,cntW + 1 });
				}
			}
		}
	}

	printf("%d", -1);
}