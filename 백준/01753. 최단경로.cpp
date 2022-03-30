#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
	int node;
	int dist;
};

struct cmp {
	bool operator()(Node right, Node left) {
		return left.dist < right.dist;
	}
};

bool compare(Node left, Node right) {
	return left.dist < right.dist;
}

int visited[20001];
int dist[20001];
vector<Node> list[20001];

int main()
{
	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		list[u].push_back({ v,w });
	}

	for (int i = 0; i <= V; i++) {
		dist[i] = -1;
	}

	for (int i = 1; i <= V; i++) {
		sort(list[i].begin(), list[i].end(), compare);
	}

	priority_queue<Node, vector<Node>, cmp> pq;

	pq.push({ K,0 });

	while (!pq.empty())
	{
		int curNode = pq.top().node;
		int curDist = pq.top().dist;
		pq.pop();

		if (visited[curNode] == 1)continue;
		visited[curNode] = 1;

		dist[curNode] = curDist;

		for (int i = 0; i < list[curNode].size(); i++) {
			pq.push({ list[curNode][i].node, list[curNode][i].dist + curDist });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] != -1) {
			printf("%d\n", dist[i]);
		}
		else {
			printf("INF\n");
		}
	}
}