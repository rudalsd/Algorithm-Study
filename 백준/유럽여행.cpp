#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//prim 알고리즘
//struct Node {
//	int node;
//	int cost;
//};
//
//struct cmp {
//	bool operator()(Node right, Node left) {
//		return left.cost < right.cost;
//	}
//};
//
//vector<Node> list[10001];
//int visited[10001];

//크루스칼 알고리즘
int vect[10001];

struct Node {
	int from;
	int to;
	int cost;
};

bool cmp(Node left, Node right)
{
	return left.cost < right.cost;
}

int Parent(int a)
{
	if (vect[a] == 0 || vect[a] == a) return a;
	int ret = Parent(vect[a]);
	vect[a] = ret;
	return ret;
}

void Union(int a, int b)
{
	vect[Parent(b)] = Parent(a);
}

int cost[10001];

int main()
{
	int N, P;
	cin >> N >> P;
	int min = 99;
	vector<Node> node;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		if (min > cost[i]) {
			min = cost[i];
		}
	}

	int dist = min;

	for (int i = 0; i < P; i++) {
		int S, E, L;
		cin >> S >> E >> L;
		node.push_back({ S,E,cost[S] + cost[E] + 2 * L });
	}

	sort(node.begin(), node.end(), cmp);

	for (int i = 0; i < node.size(); i++) {
		int from = node[i].from;
		int to = node[i].to;
		int cost = node[i].cost;

		if (Parent(from) != Parent(to)) {
			Union(from, to);
			dist += cost;
		}
	}

	//prim 알고리즘
	/*for (int i = 0; i < P; i++) {
		int S, E, L;
		cin >> S >> E >> L;
		list[S].push_back({ E,cost[S] + cost[E] + L * 2 });
		list[E].push_back({ S,cost[S] + cost[E] + L * 2 });
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ idx,0 });

	while (!pq.empty())
	{
		int curNode = pq.top().node;
		int curCost = pq.top().cost;
		pq.pop();

		if (visited[curNode] == 1)continue;
		visited[curNode] = 1;
		dist += curCost;

		for (int i = 0; i < list[curNode].size(); i++) {
			pq.push({ list[curNode][i].node, list[curNode][i].cost });
		}
	}*/

	cout << dist;
}