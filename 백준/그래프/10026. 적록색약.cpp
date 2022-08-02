#include<iostream>
#include<queue>

using namespace std;

int N;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


struct node {
	int y;
	int x;
};

void bfs(int y, int x, char ch, char temp[][101])
{
	queue<node> q;
	q.push({ y,x });
	temp[y][x] = 0;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (temp[yy][xx] == ch) {
					temp[yy][xx] = 0;
					q.push({ yy,xx });
				}
			}
		}
	}
}

void bfsRG(int y, int x, char temp[][101])
{
	queue<node> q;
	q.push({ y,x });
	temp[y][x] = 0;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (temp[yy][xx] == 'R' || temp[yy][xx] == 'G') {
					temp[yy][xx] = 0;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	char arr[101][101];
	char temp[101][101];

	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == 'R') {
				cnt++;
				bfs(i, j, 'R', temp);
			}
			else if (temp[i][j] == 'G') {
				cnt++;
				bfs(i, j, 'G', temp);
			}
			else if (temp[i][j] == 'B') {
				cnt++;
				bfs(i, j, 'B', temp);
			}
		}
	}

	printf("%d ", cnt);

	cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'R' || arr[i][j] == 'G') {
				cnt++;
				bfsRG(i, j, arr);
			}
			else if (arr[i][j] == 'B') {
				cnt++;
				bfs(i, j, 'B', arr);
			}
		}
	}

	printf("%d", cnt);
}