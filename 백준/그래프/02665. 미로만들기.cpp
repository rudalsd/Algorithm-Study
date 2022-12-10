#include<iostream>
#include<queue>

using namespace std;

int n;
char arr[51][51];
int visited[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct node {
	int y;
	int x;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
		for (int j = 0; j < n; j++) {
			visited[i][j] = 987654321;
		}
	}

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ 0,0,0 });
	visited[0][0] = 0;

	while (!pq.empty()) {
		const int y = pq.top().y;
		const int x = pq.top().x;
		const int dist = pq.top().dist;
		pq.pop();

		if (y == n - 1 && x == n - 1) {
			printf("%d", dist / 10000);
		}

		for (int i = 0; i < 4; i++) {
			const int yy = y + dy[i];
			const int xx = x + dx[i];

			if (yy >= 0 && yy < n && xx >= 0 && xx < n) {
				if (arr[yy][xx] == '1') {	//Èò ¹æ
					if (visited[yy][xx] > dist + 1) {
						visited[yy][xx] = dist + 1;
						pq.push({ yy,xx,dist + 1 });
					}
				}
				else {		//°ËÀº ¹æ
					if (visited[yy][xx] > dist + 10000) {
						visited[yy][xx] = dist + 10000;
						pq.push({ yy,xx,dist + 10000 });
					}
				}
			}
		}
	}
}