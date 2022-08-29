#include<iostream>
#include<vector>

using namespace std;

int N, M, D;
int arr[15][15];
int arrow[3];
int ans;

int cnt()		//죽인 적의 수
{
	int temp[16][15] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	int ret = 0;

	while (1) {
		vector<pair<int, int>> die;	//죽일 수 있는 적의 좌표 저장
		for (int k = 0; k < 3; k++) {
			int min = 987654321;
			int y;
			int x;
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (temp[j][i] == 1) {
						if (min > abs(arrow[k] - i) + N - j) {
							y = j;
							x = i;
							min = abs(arrow[k] - i) + N - j;
						}
					}
				}
			}
			if (min <= D) {	//거리 안에 있다면 좌표 저장
				die.push_back({ y,x });
			}
		}
		for (auto next : die) {	//좌표가 중복될 수 있으므로 한번에 처리
			if (temp[next.first][next.second] == 1) {
				temp[next.first][next.second] = 0;
				ret++;
			}
		}
		for (int i = N - 1; i >= 0; i--) {	//한칸씩 밀기
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 1) {
					temp[i + 1][j] = 1;
					temp[i][j] = 0;
				}
			}
		}

		int flag = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) break;	//적이 하나도 없다면
	}
	return ret;
}

void dfs(int level, int num)
{
	if (level == 3) {
		ans = max(cnt(), ans);
		return;
	}

	for (int i = num; i < M; i++) {	//궁수의 위치
		arrow[level] = i;
		dfs(level + 1, i + 1);
		arrow[level] = -1;
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d", ans);
}