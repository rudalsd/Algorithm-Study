#include <iostream>

using namespace std;

int N, M;
char arr[55][55];											//입력 받을 배열
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int dp[55][55];												//방문을 체크할 배열
int visited[55][55];
int Max = 0;

void dfs(int y, int x, int level)
{
	if (Max == -2) {										//Max값이 -2라면 무한루프이므로 return
		return;
	}
	if (Max < dp[y][x]) {									//dp값의 최댓값을 Max에 저장
		Max = dp[y][x];
	}
	int num = arr[y][x] - '0';

	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i] * num;
		int xx = x + dx[i] * num;
		if ((yy >= 0 && yy < N && xx >= 0 && xx < M) && arr[yy][xx] != 'H') {
			if (visited[yy][xx] != 1) {						//visited배열의 값이 1이 아닐 때 재귀
				if (dp[yy][xx] < dp[y][x] + 1) {
					visited[yy][xx] = 1;
					dp[yy][xx] = dp[y][x] + 1;
					dfs(yy, xx, level + 1);
					visited[yy][xx] = 0;
				}
			}
			else {											//visited배열의 값이 1이라면 재방문이므로 무한루프
				Max = -2;
			}
		}

	}
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0, 0);

	cout << Max + 1;
}