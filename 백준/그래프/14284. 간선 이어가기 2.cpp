#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, t;
vector<pair<int, int>> list[5001];
int visited[5001];

int main()
{
	scanf("%d %d", &n, &m);

	fill(visited, visited + n + 1, 987654321);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	scanf("%d %d", &s, &t);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,s });

	while (!pq.empty()) {
		const int cur = pq.top().second;
		const int dist = pq.top().first;
		pq.pop();

		if (cur == t) {
			printf("%d", dist);
			return 0;
		}

		if (visited[cur] < dist) continue;
		visited[cur] = dist;

		for (auto& next : list[cur]) {
			const int nextNode = next.first;
			const int nextDist = next.second;

			if (visited[nextNode] > dist + nextDist) {
				visited[nextNode] = dist + nextDist;
				pq.push({ visited[nextNode], nextNode });
			}
		}
	}
}