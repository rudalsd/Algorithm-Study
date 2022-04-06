#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct pos {
	int y;
	int x;
};

int arr[300][300];										//빙산을 나타내는 배열
int temp[300][300];										//이전의 빙산의 상태를 저장하는 배열
int visited[300][300];
int N, M;
int dy[4] = { -1,1,0,0 };								//방향배열
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x)									//bfs를 통해 이어진 빙산을 -1로 갱신
{
	memset(visited, 0, sizeof(visited));
	queue<pos> q;
	q.push({ y, x });
	temp[y][x] = -1;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		if (visited[curY][curX] == 1) continue;
		visited[curY][curX] = 1;

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (temp[yy][xx] != 0) {
				q.push({ yy,xx });
				temp[yy][xx] = -1;
			}
		}
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {							//값 입력
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int year = 0;											//햇수 초기화

	while (1)
	{
		for (int i = 0; i < N; i++) {						//temp배열에 이전의 빙산 상태 저장
			for (int j = 0; j < M; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] > 0) {						//값이 0보다 클 때 bfs 돌리기
					bfs(i, j);
					cnt++;
				}
			}
		}

		if (cnt == 0) {										//빙산이 한번에 녹아내렸을 때
			cout << 0;
			return 0;
		}
		else if (cnt > 1) {									//빙산이 2조각 이상으로 나누어졌을 때
			cout << year;
			return 0;
		}

		year++;												//햇수+1

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						int yy = i + dy[k];
						int xx = j + dx[k];
						if (temp[yy][xx] == 0) {			//바닷물에 닿아 있는 만큼 arr배열 값 -1
							arr[i][j] -= 1;
						}
					}
				}
				if (arr[i][j] < 0) {						//arr배열의 값이 0보다 작으면 0으로 갱신
					arr[i][j] = 0;
				}
			}
		}
	}
}