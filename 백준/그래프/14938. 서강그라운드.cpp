#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {		//����� ������ ������ struct
	int to;			//���� ���
	int dist;		//���� �������� �Ÿ�
};

struct cmp {		//priority_queue �� ������
	bool operator()(node right, node left)
	{
		return left.dist < right.dist;
	}
};

int n, m, r;
int item[101];		//�� ������ ������ ���� ������ �迭
vector<node> list[101];	//�׷���

int main()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {	//��� ���� Ž��
		int cnt = 0;
		priority_queue < node, vector<node>, cmp> pq;
		int visited[101] = { 0 };

		pq.push({ i, 0 });

		while (!pq.empty())
		{
			int to = pq.top().to;
			int dist = pq.top().dist;
			pq.pop();

			if (visited[to] == 1 || dist > m) continue;	//�湮�߰ų� �Ÿ��� �ָ� continue
			visited[to] = 1;
			cnt += item[to];

			for (int i = 0; i < list[to].size(); i++) {
				int next = list[to][i].to;
				int nDist = list[to][i].dist;
				if (visited[next] == 0) {
					pq.push({ next, nDist + dist });
				}
			}
		}

		if (ans < cnt) {
			ans = cnt;
		}
	}

	cout << ans;
}