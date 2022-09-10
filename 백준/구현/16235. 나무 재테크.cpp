#include<iostream>
#include<map>

using namespace std;

struct tree {
	long long energy = 5;
	int cnt;
	map<int, long long> alive;
	map<int, long long> dead;
};

int N, M, K;
int A[11][11];
tree arr[11][11];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void breeding(int y, int x)	//가을 번식
{
	for (int i = 0; i < 8; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (yy > 0 && yy <= N && xx > 0 && xx <= N) {
			arr[yy][xx].alive[1] += arr[y][x].cnt;
		}
	}
	arr[y][x].cnt = 0;
}

void seasons()	//계절 변화에 따라 map배열 갱신
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].alive.empty()) continue;
			map<int, long long> temp = arr[i][j].alive;
			arr[i][j].alive.clear();
			for (auto it = temp.begin(); it != temp.end(); it++) {	//봄
				int ret = (it->first) * (it->second);
				if (ret <= arr[i][j].energy) {
					arr[i][j].energy -= ret;
					arr[i][j].alive[(it->first) + 1] += it->second;
					if (((it->first) + 1) % 5 == 0) {
						arr[i][j].cnt += it->second;
					}
				}
				else {
					int cnt = arr[i][j].energy / (it->first);
					arr[i][j].energy -= cnt * (it->first);
					if (cnt > 0) {
						arr[i][j].alive[(it->first) + 1] += cnt;
					}
					if (((it->first) + 1) % 5 == 0) {
						arr[i][j].cnt += cnt;
					}
					arr[i][j].dead[it->first] = (it->second) - cnt;
				}
			}

			temp = arr[i][j].dead;	//여름
			for (auto it = temp.begin(); it != temp.end(); it++) {
				arr[i][j].energy += (it->first / 2) * (it->second);
			}
			arr[i][j].dead.clear();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].cnt) {
				breeding(i, j);	//가을
			}
			arr[i][j].energy += A[i][j];	//겨울
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		arr[x][y].alive[z]++;
	}

	for (int i = 0; i < K; i++) {
		seasons();
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto it = arr[i][j].alive.begin(); it != arr[i][j].alive.end(); it++) {
				ans += it->second;
			}
		}
	}

	printf("%d", ans);
}