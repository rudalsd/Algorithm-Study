#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int N;
int arr[130][130];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[130][130];

struct pos {
	int y;
	int x;
	int cur;
};

struct cmp {
	bool operator()(pos right, pos left) {
		return left.cur < right.cur;
	}
};

int main()
{
	int cnt = 1;

	while (1) {
		scanf("%d", &N);
		memset(visited, 0, sizeof(visited));

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		int ans = 0;

		priority_queue<pos, vector<pos>, cmp> pq;
		pq.push({ 0,0,arr[0][0] });

		while (!pq.empty()) {
			int y = pq.top().y;
			int x = pq.top().x;
			int cur = pq.top().cur;
			pq.pop();

			if (visited[y][x] == 1) continue;
			visited[y][x] = 1;

			if (y == N - 1 && x == N - 1) {
				ans = cur;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];

				if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
					if (visited[yy][xx] != 1) {
						pq.push({ yy,xx,cur + arr[yy][xx] });
					}
				}
			}
		}

		printf("Problem %d: %d\n", cnt, ans);
		cnt++;
	}
}