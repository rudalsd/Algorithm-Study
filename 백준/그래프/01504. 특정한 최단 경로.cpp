#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int to;
	int cost;
};

struct cmp {
	bool operator()(Node right, Node left)
	{
		return left.cost < right.cost;
	}
};

int N, E;
vector<Node> list[801];
int v[2];

int dijkstra(int start, int end)
{
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ start, 0 });
	int visited[801] = { 0 };

	while (!pq.empty())
	{
		int to = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();

		if (visited[to] == 1) continue;
		visited[to] = 1;

		if (to == end)
		{
			return cost;
		}

		for (int i = 0; i < list[to].size(); i++) {
			int next = list[to][i].to;
			int nextCost = list[to][i].cost;
			if (visited[next] != 1) {
				pq.push({ next, cost + nextCost });
			}
		}
	}

	return -1;
}

int main()
{
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	for (int i = 0; i < 2; i++) {
		cin >> v[i];
	}

	int a1 = dijkstra(1, v[0]);
	int b1 = dijkstra(1, v[1]);
	int mid = dijkstra(v[0], v[1]);
	int a2 = dijkstra(v[1], N);
	int b2 = dijkstra(v[0], N);

	int min = a1 + mid + a2;

	if (a1 != -1 && a2 != -1 && mid != -1) {
		if (min > b1 + mid + b2) {
			min = b1 + mid + b2;
		}
	}
	else {
		cout << -1;
		return 0;
	}

	cout << min;
}