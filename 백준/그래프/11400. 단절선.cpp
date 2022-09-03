#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int start;
	int end;
};

bool cmp(Edge left, Edge right)
{
	if (left.start == right.start) return left.end < right.end;
	return left.start < right.start;
}

int V, E;
vector<int> list[100001];
int id[100001];
vector<Edge> ans;
int cur = 1;

int dfs(int node, int parent)
{
	id[node] = cur++;
	int ret = id[node];

	for (auto next : list[node]) {
		if (next == parent) continue;	//�θ� �����ϰ�
		if (id[next]) {
			ret = min(ret, id[next]);
			continue;
		}

		int minId = dfs(next, node);	//�� �� �ִ� ���� ���� id

		if (minId > id[node]) {	//������ ������������ ����
			ans.push_back({ min(node,next), max(node,next) });
		}

		ret = min(ret, minId);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {
		if (!id[i]) {
			dfs(i, 0);
		}
	}

	sort(ans.begin(), ans.end(), cmp);	//���� ������ �������� �������� ����

	printf("%d\n", ans.size());

	for (auto edge : ans) {
		printf("%d %d\n", edge.start, edge.end);
	}
}