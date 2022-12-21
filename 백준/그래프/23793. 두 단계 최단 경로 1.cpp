#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int to;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int N, M;
int X, Y, Z;
vector<node> list[100001];
int visited[100001];

int dijkstra(int a, int b, int c)
{
	for (int i = 1; i <= N; i++) {
		visited[i] = 1987654321;
	}
	visited[a] = 0;
	int ret = 0;

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ a,0 });

	while (!pq.empty()) {
		const int cur = pq.top().to;
		const int dist = pq.top().dist;
		pq.pop();

		if (visited[cur] < dist) continue;

		if (cur == b) {
			return dist;
		}

		for (auto next : list[cur]) {
			const int nNode = next.to;
			const int nDist = next.dist;

			if (visited[nNode] > nDist + dist && nNode != c) {
				visited[nNode] = nDist + dist;
				pq.push({ nNode,visited[nNode] });
			}
		}
	}

	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		list[u].push_back({ v, w });
	}

	scanf("%d %d %d", &X, &Y, &Z);

	int XY = dijkstra(X, Y, 0);
	int YZ = dijkstra(Y, Z, 0);
	int XZ = dijkstra(X, Z, Y);

	if (XY == -1 || YZ == -1) {
		printf("-1 ");
	}
	else {
		printf("%d ", XY + YZ);
	}

	printf("%d", XZ);
}