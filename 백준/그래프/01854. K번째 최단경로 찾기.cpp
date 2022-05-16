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

vector<vector<Node>> list;				//�׷���
priority_queue<int> dist[1001];			//�Ÿ�

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	list.resize(n + 1);

	for (int i = 0; i < m; i++) {							//������ ������ ������ �Ÿ� �Է�
		int start, end, cost;
		cin >> start >> end >> cost;
		list[start].push_back({ end,cost });
	}

	priority_queue<Node, vector<Node>, cmp> pq;				//�Ÿ��� ª�� ������ ������ priority_queue ����
	pq.push({ 1, 0 });										//1�� ��� push
	dist[1].push(0);										//1�� ������ 1�� ������ �Ÿ� 0

	while (!pq.empty())										//���ͽ�Ʈ��
	{
		int curNode = pq.top().num;
		int curCost = pq.top().cost;
		pq.pop();

		for (int i = 0; i < list[curNode].size(); i++) {
			int nextNode = list[curNode][i].num;
			int nextCost = list[curNode][i].cost + curCost;
			if (dist[nextNode].size() < k) {				//�Ÿ� �� ����� k���� ���� ���� ���� �Ÿ� push
				dist[nextNode].push(nextCost);
				pq.push({ nextNode, nextCost });
			}
			else {
				if (dist[nextNode].top() > nextCost) {		//�Ÿ� �� ����� k���� ũ�ų� ���� �� ���� ���� k��° �Ÿ��� ������ �Ÿ����� �� Ŭ �� ���� 
					dist[nextNode].pop();					//k��° �� pop�ϰ� ���� �Ÿ� push
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