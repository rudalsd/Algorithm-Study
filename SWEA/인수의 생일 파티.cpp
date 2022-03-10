#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int node;
	int cost;
};

struct cmp {
	bool operator()(Node right, Node left) {
		return left.cost < right.cost;
	}
};

int cost[1001];
int N, M, X;

void dijkstra(vector<Node> list[])
{
	priority_queue<Node, vector<Node>, cmp> q;
	int visited[1001] = { 0 };

	Node start = { X,0 };

	q.push(start);

	while (!q.empty())
	{
		int curNode = q.top().node;
		int curCost = q.top().cost;
		q.pop();

		if (visited[curNode] == 1) continue;
		visited[curNode] = 1;

		cost[curNode] += curCost;

		for (int i = 0; i < list[curNode].size(); i++) {
			Node next = { list[curNode][i].node, list[curNode][i].cost + curCost };
			q.push(next);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<Node> list1[1001];
		vector<Node> list2[1001];

		cin >> N >> M >> X;

		for (int i = 1; i <= N; i++) {
			cost[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			Node now = { y,c };
			list1[x].push_back(now);
			now = { x,c };
			list2[y].push_back(now);
		}

		dijkstra(list1);
		dijkstra(list2);

		sort(cost + 1, cost + N + 1);

		cout << "#" << t << " " << cost[N] << endl;
	}
}