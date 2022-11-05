#include<iostream>
#include<queue>

using namespace std;

struct tomato {
	int z;
	int y;
	int x;
	int cnt;
};

int N, M, H;
int arr[100][100][100];
int visited[100][100][100];
int dz[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int ans = -1;
queue<tomato> q;


bool check()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					return false;
				}
			}
		}
	}

	return true;
}

int main()
{
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d", &arr[i][j][k]);

				if (arr[i][j][k] == 1) {
					q.push({ i,j,k,0 });
					visited[i][j][k] = 1;
				}
			}
		}
	}

	if (check()) {
		printf("%d", 0);
		return 0;
	}

	while (!q.empty()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		ans = max(ans, cnt);

		for (int i = 0; i < 6; i++) {
			int zz = z + dz[i];
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (zz >= 0 && zz < H && yy >= 0 && yy < N && xx >= 0 && xx < M) {
				if (visited[zz][yy][xx] != 1 && arr[zz][yy][xx] == 0) {
					arr[zz][yy][xx] = 1;
					visited[zz][yy][xx] = 1;
					q.push({ zz,yy,xx,cnt + 1 });
				}
			}
		}
	}

	if (check()) {
		printf("%d", ans);
	}
	else {
		printf("%d", -1);
	}
}