#include<iostream>
#include<queue>

using namespace std;

int N, K;
int arr[201][201];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct node {
	int x;
	int y;
	int cnt;
};

struct cmp {
	bool operator()(node right, node left) {
		if (left.cnt == right.cnt) return arr[left.x][left.y] < arr[right.x][right.y];
		return left.cnt < right.cnt;
	}
};

int main()
{
	scanf("%d %d", &N, &K);
	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				pq.push({ i,j,0 });
			}
		}
	}

	int S, X, Y;
	scanf("%d %d %d", &S, &X, &Y);

	while (!pq.empty()) {
		const int x = pq.top().x;
		const int y = pq.top().y;
		const int cnt = pq.top().cnt;
		pq.pop();

		if (arr[X][Y] != 0) {
			printf("%d", arr[X][Y]);
			return 0;
		}

		if (cnt == S) continue;

		for (int i = 0; i < 4; i++) {
			const int xx = x + dx[i];
			const int yy = y + dy[i];

			if (xx > 0 && xx <= N && yy > 0 && yy <= N) {
				if (arr[xx][yy] == 0) {
					arr[xx][yy] = arr[x][y];
					pq.push({ xx,yy,cnt + 1 });
				}
			}
		}
	}

	printf("%d", arr[X][Y]);
}