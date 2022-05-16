#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[110][110];
int temp[110][110];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct pos {
	int y;
	int x;
};

void bfs(int y, int x)													//이어진 땅을 체크하는 bfs 함수
{
	int visited[110][110] = { 0 };
	queue<pos> q;
	q.push({ y,x });

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		if (visited[curY][curX] == 1) continue;							//방문했던 곳이면 continue
		visited[curY][curX] = 1;										//방문할 때마다 1로 변환

		for (int i = 0; i < 4; i++) {
			int yy = curY + dy[i];
			int xx = curX + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if (visited[yy][xx] != 1 && temp[yy][xx] > 0) {			//가려고 하는 땅이 방문하지 않았거나 물에 잠기지 않았으면 q에 넣기
					temp[yy][xx] = -1;									//들른 땅이면 -1로 초기화
					q.push({ yy,xx });
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	int height = 0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {									//가장 높은 봉우리를 height에 저장
			cin >> arr[i][j];
			if (height < arr[i][j]) {
				height = arr[i][j];
			}
		}
	}

	for (int h = 0; h < height; h++) {									//높이가 0인 봉우리부터 height-1인 봉우리까지 점차적으로 물에 잠그면서 체크
		int result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {								//높이가 h보다 낮으면 물에 잠그고 0으로 표시
				if (arr[i][j] <= h) {
					arr[i][j] = 0;
				}
				temp[i][j] = arr[i][j];									//temp배열에 다시 저장
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {								//아직 방문하지 않은 땅마다 들리면서 bfs로 체크
				if (temp[i][j] > 0) {
					result++;
					bfs(i, j);
				}
			}
		}
		if (max < result) {												//제일 땅이 많을 때를 max에 저장
			max = result;
		}
	}

	cout << max;
}