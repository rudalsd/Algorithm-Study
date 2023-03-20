#include<iostream>
#include<vector>
#include<queue>
#define ll long long

using namespace std;

struct node {
	int cur;
	ll cost;
	int used;
};

struct cmp {
	bool operator()(node right, node left)
	{
		return left.cost < right.cost;
	}
};

int n, m, f, s, t;
vector<pair<int, int>> list[50000];
ll visited[50000][2];

int main()
{
	scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
	for (int i = 0; i < n; i++) {
		visited[i][0] = visited[i][1] = 3333333333;
	}

	for (int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);

		list[u].push_back({ v,c });
		list[v].push_back({ u,c });
	}

	for (int i = 0; i < f; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		list[u].push_back({ v,0 });
	}

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ s,0,0 });

	while (!pq.empty()) {
		const int cur = pq.top().cur;
		const ll cost = pq.top().cost;
		const int used = pq.top().used;
		pq.pop();

		if (visited[cur][used] < cost) continue;
		visited[cur][used] = cost;

		if (cur == t) {
			printf("%lld", cost);
			return 0;
		}

		for (auto& next : list[cur]) {
			if (used == 0 && next.second == 0) {
				if (visited[next.first][1] > cost) {
					visited[next.first][1] = cost;
					pq.push({ next.first, cost, 1 });
				}
			}
			else if (next.second != 0) {
				if (visited[next.first][used] > cost + next.second) {
					visited[next.first][used] = cost + next.second;
					pq.push({ next.first, visited[next.first][used], used});
				}
			}
		}
	}
}