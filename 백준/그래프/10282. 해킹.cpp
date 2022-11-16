#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, d, c;
int visited[10001];

struct cmp {
	bool operator()(pair<int, int> right, pair<int, int> left) {
		return left.second < right.second;
	}
};

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d %d", &n, &d, &c);
		vector<pair<int, int>> list[10001];

		memset(visited, -1, 4 * (n + 1));

		for (int i = 0; i < d; i++) {
			int a, b, s;
			scanf("%d %d %d", &a, &b, &s);

			list[b].push_back({ a,s });
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

		pq.push({ c,0 });

		int ans = 0;

		while (!pq.empty()) {
			int cur = pq.top().first;
			int dist = pq.top().second;
			pq.pop();

			if (visited[cur] != -1 && visited[cur] < dist) continue;
			visited[cur] = dist;

			ans = max(ans, dist);

			for (auto next : list[cur]) {
				if (visited[next.first] == -1 || visited[next.first] > next.second + dist) {
					visited[next.first] = next.second + dist;
					pq.push({ next.first, next.second + dist });
				}
			}
		}

		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (visited[i] != -1) {
				cnt++;
			}
		}

		printf("%d %d\n", cnt, ans);
	}
}