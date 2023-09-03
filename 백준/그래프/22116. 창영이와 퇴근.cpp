#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct node {
	int y, x, h;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.h < right.h;
	}
};

int N;
int arr[1000][1000];
int visited[1000][1000];
int ans;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			visited[i][j] = 1111111111;
		}
	}

	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ 0,0,0 });
	visited[0][0] = 0;

	while (!pq.empty()) {
		const int y = pq.top().y;
		const int x = pq.top().x;
		const int h = pq.top().h;
		pq.pop();

		if (visited[y][x] < h) continue;

		ans = max(ans, h);

		if (y == N - 1 && x == N - 1) {
			cout << ans;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < N && xx >= 0 && xx < N) {
				int diff = abs(arr[y][x] - arr[yy][xx]);
				if (visited[yy][xx] > diff) {
					visited[yy][xx] = diff;
					pq.push({ yy,xx,diff });
				}
			}
		}
	}
}