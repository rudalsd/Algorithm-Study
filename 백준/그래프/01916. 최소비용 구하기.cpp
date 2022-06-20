#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {
	int to;
	int cost;
};

struct cmp {
	bool operator()(Node right, Node left) {
		return left.cost < right.cost;
	}
};

int N, M;
int from, to;
vector<Node> list[1001];
int visited[1001];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		list[start].push_back({ end,cost });
	}

	cin >> from >> to;

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({ from, 0 });

	while (!pq.empty())
	{
		int curTo = pq.top().to;
		int curCost = pq.top().cost;
		pq.pop();

		if (visited[curTo] == 1) continue;
		visited[curTo] = 1;

		if (curTo == to) {
			cout << curCost;
			return 0;
		}

		for (int i = 0; i < list[curTo].size(); i++) {
			int next = list[curTo][i].to;
			int nextCost = list[curTo][i].cost;
			if (visited[next] != 1) {
				pq.push({ next,curCost + nextCost });
			}
		}
	}
}