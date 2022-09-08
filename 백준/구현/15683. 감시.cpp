#include<iostream>
#include<vector>

using namespace std;

int N, M;
int arr[8][8];
int limit;
vector<pair<int, int>> pos;
int ans = 987654321;

void cctv(int y, int x, int dir)	//cctv가 보는 방향을 #으로 초기화
{
	if (dir == 0) {
		for (int i = 1; i < M; i++) {
			if (x + i >= M) break;
			int temp = arr[y][x + i];
			if (temp == 6) {
				break;
			}
			else if (temp > 0 && temp < 6) {
				continue;
			}
			else {
				arr[y][x + i] = '#';
			}

		}
	}
	else if (dir == 1) {
		for (int i = 1; i < N; i++) {
			if (y + i >= N) break;
			int temp = arr[y + i][x];
			if (temp == 6) {
				break;
			}
			else if (temp > 0 && temp < 6) {
				continue;
			}
			else {
				arr[y + i][x] = '#';
			}

		}
	}
	else if (dir == 2) {
		for (int i = 1; i < M; i++) {
			if (x - i < 0) break;
			int temp = arr[y][x - i];
			if (temp == 6) {
				break;
			}
			else if (temp > 0 && temp < 6) {
				continue;
			}
			else {
				arr[y][x - i] = '#';
			}

		}
	}
	else {
		for (int i = 1; i < N; i++) {
			if (y - i < 0) break;
			int temp = arr[y - i][x];
			if (temp == 6) {
				break;
			}
			else if (temp > 0 && temp < 6) {
				continue;
			}
			else {
				arr[y - i][x] = '#';
			}

		}
	}
}

int blind()	//사각지대 개수 세기
{
	int ret = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				ret++;
			}
		}
	}

	return ret;
}

void dfs(int level)
{
	if (level == limit) {
		int cnt = blind();
		ans = min(ans, cnt);
		return;
	}

	int temp[8][8] = { 0 };
	for (int i = 0; i < N; i++) {	//백트래킹을 위한 저장
		for (int j = 0; j < M; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	int y = pos[level].first;
	int x = pos[level].second;
	int num = arr[y][x];

	if (num == 1) {	//1번 cctv
		for (int i = 0; i < 4; i++) {
			cctv(y, x, i);
			dfs(level + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
	else if (num == 2) {	//2번 cctv
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				cctv(y, x, 0);
				cctv(y, x, 2);
			}
			else {
				cctv(y, x, 1);
				cctv(y, x, 3);
			}
			dfs(level + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
	else if (num == 3) {	//3번 cctv
		for (int i = 0; i < 4; i++) {
			int dir1 = 0 + i;
			int dir2 = 1 + i;
			if (dir2 > 3) {
				dir2 -= 4;
			}
			cctv(y, x, dir1);
			cctv(y, x, dir2);
			dfs(level + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
	else if (num == 4) {	//4번 cctv
		for (int i = 0; i < 4; i++) {
			int dir1 = 0 + i;
			int dir2 = 1 + i;
			int dir3 = 2 + i;
			if (dir2 > 3) {
				dir2 -= 4;
			}
			if (dir3 > 3) {
				dir3 -= 4;
			}
			cctv(y, x, dir1);
			cctv(y, x, dir2);
			cctv(y, x, dir3);
			dfs(level + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr[i][j] = temp[i][j];
				}
			}
		}
	}
	else {	//5번 cctv
		for (int i = 0; i < 4; i++) {
			cctv(y, x, i);
		}
		dfs(level + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = temp[i][j];
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
			if (arr[i][j] > 0 && arr[i][j] < 6) {
				pos.push_back({ i, j });
				limit++;
			}
		}
	}

	dfs(0);

	printf("%d", ans);
}