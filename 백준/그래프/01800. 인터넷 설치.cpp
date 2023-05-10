#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int cur;
	int cost;
	int cnt;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.cost < right.cost;
	}
};

int N, P, K;
vector<pair<int, int>> list[1001];
int visited[1001][1001];

int main()
{
	scanf("%d %d %d", &N, &P, &K);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 1111111111;
		}
	}

	for (int i = 0; i < P; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	priority_queue<node, vector<node>, cmp> pq;
	vector<int> temp;

	pq.push({ 1,0,0 });

	while (!pq.empty()) {
		const int cur = pq.top().cur;
		const int cost = pq.top().cost;
		const int cnt = pq.top().cnt;
		pq.pop();

		if (visited[cur][cnt] < cost) continue;
		visited[cur][cnt] = cost;

		if (cur == N) {
			printf("%d", cost);
			return 0;
		}

		for (auto& next : list[cur]) {
			const int nNode = next.first;
			const int nCost = next.second;

			if (cnt < K) {
				if (visited[nNode][cnt + 1] > cost) {
					pq.push({ nNode,cost,cnt+1 });
				}
			}

			if (visited[nNode][cnt] > max(cost, nCost)) {
				pq.push({ nNode,max(cost,nCost),cnt });
			}
		}
	}

	printf("-1");
}