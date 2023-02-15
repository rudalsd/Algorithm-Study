#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int V, E, P;
int visited[5001];
vector<pair<int, int>> list[5001];

int dijkstra(int a, int b)
{
	fill(visited, visited + V + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	pq.push({ 0,a });
	visited[a] = 0;

	while (!pq.empty()) {
		const int cur = pq.top().second;
		const int dist = pq.top().first;
		pq.pop();

		if (cur == b) {
			return dist;
		}

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

int main()
{
	scanf("%d %d %d", &V, &E, &P);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	if (dijkstra(1, P) + dijkstra(P, V) == dijkstra(1, V)) {
		printf("SAVE HIM");
	}
	else {
		printf("GOOD BYE");
	}
}