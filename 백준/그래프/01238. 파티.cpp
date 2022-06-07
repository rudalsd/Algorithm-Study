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
vector<Node> list[1001];		//�������� ���������� ������ vector list
vector<Node> relist[1001];		//�������� ���������� ������ vector relist
int dist[1001];

void dijkstra(vector<Node> list[])		//�� ������ ����Ͽ� �� ������ �Ÿ��� dist �迭�� ����
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
		list[A].push_back({ B,T });		//������ ���������� ����
		relist[B].push_back({ A,T });	//������ ���������� ����
	}

	int ans = 0;

	dijkstra(list);		//������ dijkstra
	dijkstra(relist);	//������ dijkstra

	for (int i = 1; i <= N; i++) {
		if (ans < dist[i]) {
			ans = dist[i];	//�Ÿ��� �ִ��� ans�� ����
		}
	}

	cout << ans;
}