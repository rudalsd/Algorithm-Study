#include<iostream>
#include<queue>

using namespace std;

int N, M;
int Sx, Sy, Ex, Ey;
int arr[101][101];
int visited[101][101][3];

int dx[3][4] = {
	-1,1,0,0,
	-1,1,0,0,
	0,0,0,0
};

int dy[3][4] = {
	0,0,-1,1,
	0,0,0,0,
	-1,1,0,0,
};

struct node {
	int x;
	int y;
	int cnt;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &Sx, &Sy, &Ex, &Ey);

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				visited[j][k][i] = 987654321;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ Sx,Sy,1,0 });
	visited[Sx][Sy][1] = 0;

	while (!pq.empty()) {
		const int x = pq.top().x;
		const int y = pq.top().y;
		const int cnt = pq.top().cnt % 3;
		const int dist = pq.top().dist;
		pq.pop();

		if (y == Ey && x == Ex) {
			printf("%d", dist);
			return 0;
		}

		if (cnt == 0) {
			for (int i = 0; i < 4; i++) {
				const int yy = y + dy[cnt][i];
				const int xx = x + dx[cnt][i];

				if (yy > 0 && xx <= N && xx > 0 && yy <= M) {
					if (visited[xx][yy][1] > dist + arr[xx][yy] && arr[xx][yy] != -1) {
						visited[xx][yy][1] = dist + arr[xx][yy];
						pq.push({ xx,yy,1,dist + arr[xx][yy] });
					}
				}
			}
		}
		else if (cnt == 1) {
			for (int i = 0; i < 2; i++) {
				const int yy = y + dy[cnt][i];
				const int xx = x + dx[cnt][i];

				if (yy > 0 && xx <= N && xx > 0 && yy <= M) {
					if (visited[xx][yy][2] > dist + arr[xx][yy] && arr[xx][yy] != -1) {
						visited[xx][yy][2] = dist + arr[xx][yy];
						pq.push({ xx,yy,2,dist + arr[xx][yy] });
					}
				}
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				const int yy = y + dy[cnt][i];
				const int xx = x + dx[cnt][i];

				if (yy > 0 && xx <= N && xx > 0 && yy <= M) {
					if (visited[xx][yy][0] > dist + arr[xx][yy] && arr[xx][yy] != -1) {
						visited[xx][yy][0] = dist + arr[xx][yy];
						pq.push({ xx,yy,0,dist + arr[xx][yy] });
					}
				}
			}
		}
	}

	printf("-1");
}