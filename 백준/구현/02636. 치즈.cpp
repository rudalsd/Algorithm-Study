#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int arr[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int temp[100][100];
int visited[100][100];
int ans;
int ansC;

bool check(int y, int x)	//공기 중에 노출 된 치즈 찾기
{
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (temp[yy][xx] == 2) {
			return true;
		}
	}

	return false;
}

void bfs()		//공기를 찾는 bfs
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	memset(temp, 0, sizeof(temp));
	memset(visited, 0, sizeof(visited));
	temp[0][0] = 2;
	visited[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (arr[yy][xx] == 0 && visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					temp[yy][xx] = 2;
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (1) {
		bfs();
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					if (check(i, j)) {
						temp[i][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 1) {
					arr[i][j] = 0;
				}
			}
		}

		if (cnt == 0) {
			printf("%d\n%d", ansC, ans);
			return 0;
		}

		ans = cnt;
		ansC++;
	}
}