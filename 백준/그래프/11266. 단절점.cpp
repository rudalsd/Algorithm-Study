#include<iostream>
#include<vector>

using namespace std;

int V, E;
vector<int> list[10001];
int id[10001];
int ans[10001];
int cur = 1;

int dfs(int node, bool root)
{
	id[node] = cur++;
	int ret = id[node];
	int child = 0;

	for (auto next : list[node]) {
		if (id[next]) {	//�̹� �湮�ߴٸ�
			ret = min(ret, id[next]);
			continue;
		}
		child++;	//�ڽ��� ����

		int minId = dfs(next, false);	//���� �ִ� ��� �� ���� id���� ���� ���

		if (!root && minId >= id[node]) {	//��Ʈ�� �ƴϰ� �ڽź��� �� ���� id���� ���� ���� ���� ���� ��
			ans[node] = 1;
		}

		ret = min(ret, minId);
	}

	if (root && child > 1) {
		ans[node] = 1;
	}

	return ret;
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {		//�׷��� �����
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {	//�湮���� ���� �����
		if (!id[i]) {
			dfs(i, true);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= V; i++) {	//�������� ����
		if (ans[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= V; i++) {	//������ ���
		if (ans[i] == 1) printf("%d ", i);
	}
}