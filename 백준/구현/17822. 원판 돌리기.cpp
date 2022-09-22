#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M, T;
int arr[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int flag = false;
int ans;

void average()	//평균과 비교하여 숫자 갱신
{
	int sum = 0;
	int cnt = 0;
	float avr;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] > 0) {
				sum += arr[i][j];
				cnt++;
			}
		}
	}

	avr = sum / (float)cnt;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] > 0) {
				if ((float)arr[i][j] > avr) {
					arr[i][j]--;
				}
				else if ((float)arr[i][j] < avr) {
					arr[i][j]++;
				}
			}
		}
	}
}

void bfs(int y, int x, int num)		//인접한 숫자 찾기
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> temp;
	int visited[51][51] = { 0 };
	visited[y][x] = 1;
	q.push({ y,x });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		temp.push_back({ y,x });	//인접한 숫자의 좌표 저장
		q.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (xx == 0) xx = M;
			if (xx > M) xx = 1;
			if (yy > 0 && yy <= N) {
				if (visited[yy][xx] != 1) {
					visited[yy][xx] = 1;
					if (arr[yy][xx] == num) {
						q.push({ yy,xx });
					}
				}
			}
		}
	}

	if (temp.size() > 1) {	//인접한 숫자가 있다면
		for (auto next : temp) {
			int y = next.first;
			int x = next.second;

			arr[y][x] = 0;
			flag = true;
		}
	}
}

void move(int arr[51], int dir, int k) //원하는 방향으로 원판 돌리기
{
	for (int j = 0; j < k; j++) {
		if (dir == 0) {
			int temp = arr[M];
			for (int i = M; i > 1; i--) {
				arr[i] = arr[i - 1];
			}
			arr[1] = temp;
		}
		else {
			int temp = arr[1];
			for (int i = 1; i < M; i++) {
				arr[i] = arr[i + 1];
			}
			arr[M] = temp;
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &T);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k;
		flag = false;
		scanf("%d %d %d", &x, &d, &k);

		for (int j = 1; j <= N; j++) {
			if (j % x == 0) {
				move(arr[j], d, k);
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] != 0) {
					bfs(i, j, arr[i][j]);
				}
			}
		}

		if (!flag) {
			average();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += arr[i][j];
		}
	}

	printf("%d", ans);
}