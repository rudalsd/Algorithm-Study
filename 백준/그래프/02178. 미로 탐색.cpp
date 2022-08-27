#include<iostream>
#include<queue>

using namespace std;

struct node {
	int y;
	int x;
	int cnt;
};

int N, M;
char arr[100][101];
int visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	queue<node> q;
	q.push({ 0,0,1 });

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (y == N - 1 && x == M - 1) {
			printf("%d", cnt);
			return 0;
		}

		if (visited[y][x]) continue;
		visited[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == '1' && visited[yy][xx] != 1) {
					q.push({ yy,xx,cnt + 1 });
				}
			}
		}
	}
}