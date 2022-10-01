#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int arr[21][21];
int temp[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int point;

struct status {
	vector<pair<int, int>> vect;
	int cnt;
};

void turn()		//반시계방향 회전
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[N - 1 - j][i] = arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void gravity()		//중력 작용
{
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (arr[j][i] >= 0 && arr[j + 1][i] == -2) {
				arr[j + 1][i] = arr[j][i];
				arr[j][i] = -2;
				j += 2;
			}
		}
	}
}

status bfs(int cury, int curx, int num)	//같은 색과 무지개 색의 블록 좌표, 무지개 색 블록 개수 return
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> vect;
	q.push({ cury,curx });
	vect.push_back({ cury,curx });
	int visited[21][21] = { 0 };
	visited[cury][curx] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				if ((arr[yy][xx] == 0 || arr[yy][xx] == num) && !visited[yy][xx]) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
					vect.push_back({ yy,xx });
					if (arr[yy][xx] == 0) {
						cnt++;
					}
					else {
						temp[yy][xx] = 1;
					}
				}
			}
		}
	}

	return { vect,cnt };
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}


	while (1) {
		memset(temp, 0, sizeof(temp));
		status ans;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (temp[i][j] == 0 && arr[i][j] > 0) {
					status temp = bfs(i, j, arr[i][j]);

					if (ans.vect.size() < temp.vect.size()) {
						ans = temp;
					}
					else if (ans.vect.size() == temp.vect.size()) {
						if (ans.cnt <= temp.cnt) {
							ans = temp;
						}
					}
				}
			}
		}

		for (auto next : ans.vect) {
			int y = next.first;
			int x = next.second;
			arr[y][x] = -2;
		}

		int size = ans.vect.size();

		if (size <= 1) {
			printf("%d", point);
			return 0;
		}

		point += size * size;

		gravity();

		turn();

		gravity();
	}
}