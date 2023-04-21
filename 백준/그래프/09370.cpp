#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

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

vector<pair<int, int>> list[2001];

int n, m, t;
int s, g, h;
int visiteds[2001];
int visitedg[2001];
int visitedh[2001];
int des[100];
int dist;

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {

		priority_queue<node, vector<node>, cmp> pq;

		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		for (int i = 1; i <= n; i++) {
			visiteds[i] = 987654321;
			visitedg[i] = 987654321;
			visitedh[i] = 987654321;
			list[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);

			list[a].push_back({ b,d });
			list[b].push_back({ a,d });
		}

		for (int i = 0; i < t; i++) {
			scanf("%d", &des[i]);
		}

		sort(des, des + t);

		pq.push({ s,0 });

		while (!pq.empty()) {
			const int cur = pq.top().to;
			const int dist = pq.top().dist;
			pq.pop();

			if (visiteds[cur] < dist) continue;
			visiteds[cur] = dist;

			for (auto& next : list[cur]) {
				const int nextNode = next.first;
				const int nextDist = next.second;

				if (visiteds[nextNode] > nextDist + dist) {
					visiteds[nextNode] = nextDist + dist;
					pq.push({ nextNode,nextDist + dist });
				}
			}
		}

		pq.push({ g,0 });

		while (!pq.empty()) {
			const int cur = pq.top().to;
			const int dist = pq.top().dist;
			pq.pop();

			if (visitedg[cur] < dist) continue;
			visitedg[cur] = dist;

			for (auto& next : list[cur]) {
				const int nextNode = next.first;
				const int nextDist = next.second;

				if (visitedg[nextNode] > nextDist + dist) {
					visitedg[nextNode] = nextDist + dist;
					pq.push({ nextNode,nextDist + dist });
				}
			}
		}

		pq.push({ h,0 });

		while (!pq.empty()) {
			const int cur = pq.top().to;
			const int dist = pq.top().dist;
			pq.pop();

			if (visitedh[cur] < dist) continue;
			visitedh[cur] = dist;

			for (auto& next : list[cur]) {
				const int nextNode = next.first;
				const int nextDist = next.second;

				if (visitedh[nextNode] > nextDist + dist) {
					visitedh[nextNode] = nextDist + dist;
					pq.push({ nextNode,nextDist + dist });
				}
			}
		}

		for (int i = 0; i < t; i++) {
			if ((visiteds[g] + visitedg[h] + visitedh[des[i]] == visiteds[des[i]]) || (visiteds[h] + visitedh[g] + visitedg[des[i]] == visiteds[des[i]])) {
				printf("%d ", des[i]);
			}
		}

		printf("\n");
	}
}
