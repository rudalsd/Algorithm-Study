#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int num;
	int cost;
};

struct cmp {
	bool operator()(Node right, Node left) {
		return left.cost < right.cost;
	}
};

vector<vector<Node>> list;				//그래프
priority_queue<int> dist[1001];			//거리

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	list.resize(n + 1);

	for (int i = 0; i < m; i++) {							//각각의 노드부터 노드까지 거리 입력
		int start, end, cost;
		cin >> start >> end >> cost;
		list[start].push_back({ end,cost });
	}

	priority_queue<Node, vector<Node>, cmp> pq;				//거리가 짧은 순으로 들어가도록 priority_queue 생성
	pq.push({ 1, 0 });										//1번 노드 push
	dist[1].push(0);										//1번 노드부터 1번 노드까지 거리 0

	while (!pq.empty())										//다익스트라
	{
		int curNode = pq.top().num;
		int curCost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < list[curNode].size(); i++) {
			int nextNode = list[curNode][i].num;
			int nextCost = list[curNode][i].cost + curCost;
			if (dist[nextNode].size() < k) {				//거리 힙 사이즈가 k보다 작을 때는 힙에 거리 push
				dist[nextNode].push(nextCost);
				pq.push({ nextNode, nextCost });
			}
			else {
				if (dist[nextNode].top() > nextCost) {		//거리 힙 사이즈가 k보다 크거나 같을 때 만약 힙의 k번째 거리가 지금의 거리보다 더 클 때 힙의 
					dist[nextNode].pop();					//k번째 수 pop하고 지금 거리 push
					dist[nextNode].push(nextCost);
					pq.push({ nextNode,nextCost });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << -1 << endl;
		}
		else {
			cout << dist[i].top() << endl;
		}
	}
}