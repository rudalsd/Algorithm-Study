#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M;
vector<pair<int, int>> list[50001];
int visited[50001];

int main()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	scanf("%d %d", &N, &M);

	fill(visited, visited + N + 1, 987654321);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);

		list[A].push_back({ B,C });
		list[B].push_back({ A,C });
	}

	pq.push({ 0,1 });

	while (!pq.empty()) {
		const int cur = pq.top().second;
		const int dist = pq.top().first;
		pq.pop();

		if (cur == N) {
			printf("%d", dist);
			return 0;
		}

		if (visited[cur] < dist) continue;
		visited[cur] = dist;

		for (auto& next : list[cur]) {
			const int nNode = next.first;
			const int nDist = next.second;

			if (visited[nNode] > dist + nDist) {
				visited[nNode] = dist + nDist;
				pq.push({ visited[nNode], nNode });
			}
		}
	}
}