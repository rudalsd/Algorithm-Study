#include<iostream>
#include<queue>

using namespace std;

struct node {
	int x, y, z;
};

int T, M;
int arr[101][101][101];
int visited[101][101][101];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

bool bfs(int x, int y, int z)
{
	bool ret = true;

	queue<node> q;
	q.push({ x,y,z });

	while (!q.empty()) {
		const int x = q.front().x;
		const int y = q.front().y;
		const int z = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int zz = z + dz[i];

			if (xx >= 1 && xx <= 100 && yy >= 1 && yy <= 100 && zz >= 1 && zz <= 100) {
				if (visited[xx][yy][zz] == 0 && arr[xx][yy][zz] == 0) {
					visited[xx][yy][zz] = 1;
					q.push({ xx,yy,zz });
				}
			}
			else {
				ret = false;
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> M;

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				for (int k = 1; k <= 100; k++) {
					visited[i][j][k] = 0;
					arr[i][j][k] = 0;
				}
			}
		}

		for (int i = 0; i < M; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			arr[x][y][z] = 1;
		}

		int ans = 0;

		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				for (int k = 1; k <= 100; k++) {
					if (arr[i][j][k] == 0 && visited[i][j][k] == 0) {
						visited[i][j][k] = 1;
						if (bfs(i, j, k)) ans++;
					}
				}
			}
		}

		cout << ans << '\n';
	}
}
