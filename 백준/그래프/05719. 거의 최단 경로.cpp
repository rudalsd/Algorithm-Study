#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct node {
	int to;
	int dist;
};

struct cmp {
	bool operator()(node right, node left)
	{
		return left.dist < right.dist;
	}
};

int N, M, S, D;
vector<vector<node>> list;		//�׷���
vector<vector<int>> link;		//link[i] = {j} j->i������ �Ÿ��� �ִܰŸ�
int routed[500][500];			//���� ����
int dijk[500];			//�� �������� �ִ� �Ÿ�


int dijkstra()		//�ִ� �Ÿ��� ���ϴ� �Լ�
{
	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ S,0 });

	for (int i = 0; i < N; i++) {
		dijk[i] = 987654321;
	}

	dijk[S] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().to;
		int dist = pq.top().dist;
		pq.pop();

		if (dijk[cur] < dist) continue;	//�ִ� �Ÿ��� �ƴ϶��

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i].to;
			int nDist = list[cur][i].dist;

			if (routed[cur][next] == 1) {	//����� �����̶��
				continue;
			}

			if (dijk[next] == dist + nDist) {	//�ִܰŸ��� ���ٸ�
				link[next].push_back(cur);
			}
			else if (dijk[next] > dist + nDist) {	//�ִ� �Ÿ��� ���ŵȴٸ�
				link[next].clear();
				link[next].push_back(cur);

				dijk[next] = dist + nDist;
				pq.push({ next,dist + nDist });
			}
		}
	}

	return dijk[D] == 987654321 ? -1 : dijk[D];
}

void remove(int cur)
{
	for (int i = 0; i < link[cur].size(); i++) {	//���� ��忡 ����� �ִ� �Ÿ� ���
		int node = link[cur][i];
		if (routed[node][cur] != 1) {
			routed[node][cur] = 1;		//��ο��� ����

			remove(node);			//����� ��忡 �� ����� �ִ� �Ÿ� ���� ����
		}
	}
}

int main()
{
	while (1) {
		scanf("%d %d", &N, &M);
		memset(routed, 0, sizeof(routed));

		list.clear();
		list.resize(N);
		link.clear();
		link.resize(N);

		if (N == 0) {
			break;
		}

		scanf("%d %d", &S, &D);

		for (int i = 0; i < M; i++) {
			int U, V, P;
			scanf("%d %d %d", &U, &V, &P);
			list[U].push_back({ V,P });
		}

		dijkstra();
		remove(D);
		printf("%d\n", dijkstra());
	}
}