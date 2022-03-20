#include<iostream>
#include<queue>

using namespace std;

int N, M;
int arr[50][50];
int visited[50][50];
int room[300];

int dirY[16][4] = {
	-1,1,0,0,
	-1,1,0,0,
	0,1,0,0,
	0,1,0,0,
	-1,1,0,0,
	-1,1,0,0,
	0,1,0,0,
	0,1,0,0,
	-1,0,0,0,
	-1,0,0,0,
	0,0,0,0,
	0,0,0,0,
	-1,0,0,0,
	-1,0,0,0,
	0,0,0,0,
	0,0,0,0
};
int dirX[16][4] = {
	0,0,-1,1,
	0,0,1,0,
	0,0,-1,1,
	0,0,0,1,
	0,0,-1,0,
	0,0,0,0,
	0,0,-1,0,
	0,0,0,0,
	0,0,-1,1,
	0,0,0,1,
	0,0,-1,1,
	0,0,0,1,
	0,0,-1,0,
	0,0,0,0,
	0,0,-1,0,
	0,0,0,0
};

struct pos {
	int y;
	int x;
};

int num = -1;

int bfs(int y, int x)
{
	int visited[50][50] = { 0 };
	queue<pos> q;
	q.push({ y,x });

	int cnt = 0;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		if (visited[curY][curX] == 1)continue;
		visited[curY][curX] = 1;
		cnt++;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dirY[arr[curY][curX]][i];
			int xx = curX + dirX[arr[curY][curX]][i];
			if (arr[yy][xx] >= 0) {
				q.push({ yy,xx });
			}
		}

		arr[curY][curX] = num;
	}

	return cnt;
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int max = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] >= 0) {
				cnt++;
				int ret = bfs(i, j);
				if (max < ret) {
					max = ret;
				}
				room[num * -1] = ret;
				num--;
			}
		}
	}

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };
	int size = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];
				if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
					if (arr[i][j] != arr[yy][xx]) {
						int sum = room[-arr[i][j]] + room[-arr[yy][xx]];
						if (size < sum) {
							size = sum;
						}
					}
				}
			}
		}
	}

	cout << cnt << endl << max << endl << size;
}