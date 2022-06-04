#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Bus {					//�뼱�� ������ ������ struct
	int to;
	int cost;
	vector<int> via;
};

int n, m;
int visited[1001];			//�湮 ���� üũ
vector<Bus> list[1001];		//���� �������� cost�� ������ vector list

bool cmp(Bus left, Bus right)	//������ ���� ������ list�� ����
{
	return left.cost < right.cost;
}

struct comp {					//������ ���� ������ priority_queue���� ��������
	bool operator()(Bus right, Bus left)
	{
		return left.cost < right.cost;
	}
};

int main()
{
	int start, end;
	int ans;				//�� ���� ������ ����
	vector<int> ansVia;		//��θ� ������ vector
	cin >> n >> m;

	for (int i = 0; i < m; i++) {	//�뼱 ������ list�� �Է�
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		list[start].push_back({ end,cost });
	}

	cin >> start >> end;

	for (int i = 1; i <= n; i++) {	//������ ���� ������ ����
		sort(list[i].begin(), list[i].end(), cmp);
	}

	priority_queue<Bus, vector<Bus>, comp> pq;
	vector<int> via;
	pq.push({ start,0, via });		//�������� pq�� �ֱ�


	while (!pq.empty())
	{
		int to = pq.top().to;
		int cost = pq.top().cost;
		vector<int> via = pq.top().via;

		pq.pop();

		if (visited[to] == 1) continue;	//�湮�ߴٸ� continue
		visited[to]++;
		via.push_back(to);

		if (to == end) {		//�������� �����ϸ� ���� ��θ� ����
			ans = cost;
			ansVia = via;
			break;
		}

		for (int i = 0; i < list[to].size(); i++) {
			int next = list[to][i].to;
			int nextCost = list[to][i].cost;
			if (visited[next] != 1) {		//�湮���� �ʾҴٸ�
				pq.push({ next, cost + nextCost, via });	//���� ���� ������� ���µ� ��� ���, ��θ� pq�� �ֱ�
			}
		}
	}

	printf("%d\n%d\n", ans, ansVia.size());		//���
	for (int i = 0; i < ansVia.size(); i++) {
		printf("%d ", ansVia[i]);
	}
}