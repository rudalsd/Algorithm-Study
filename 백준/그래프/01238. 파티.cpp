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

int N, M, X;
vector<Node> list[1001];		//간선들을 정방향으로 저장할 vector list
vector<Node> relist[1001];		//간선들을 역방향으로 저장할 vector relist
int dist[1001];

void dijkstra(vector<Node> list[])		//한 점에서 출발하여 각 노드까지 거리를 dist 배열에 저장
{
	int visited[1001] = { 0 };
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ X, 0 });

	while (!pq.empty())
	{
		int node = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();

		if (visited[node]) continue;
		visited[node]++;
		dist[node] += cost;

		for (int i = 0; i < list[node].size(); i++) {
			int next = list[node][i].to;
			int nextCost = list[node][i].cost;
			if (visited[next] != 1) {
				pq.push({ next, cost + nextCost });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int A, B, T;
		scanf("%d %d %d", &A, &B, &T);
		list[A].push_back({ B,T });		//간선을 정방향으로 저장
		relist[B].push_back({ A,T });	//간선을 역방향으로 저장
	}

	int ans = 0;

	dijkstra(list);		//정방향 dijkstra
	dijkstra(relist);	//역방향 dijkstra

	for (int i = 1; i <= N; i++) {
		if (ans < dist[i]) {
			ans = dist[i];	//거리의 최댓값을 ans에 저장
		}
	}

	cout << ans;
}