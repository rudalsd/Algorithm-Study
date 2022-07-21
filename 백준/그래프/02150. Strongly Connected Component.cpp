#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace  std;
int V, E;
vector<int> list[10001];		//�׷��� ������ �迭
int id[10001];					//�湮�� ������ ������ �迭
int seq = 1;					//�湮�� ����
int fin[10001];					//scc ����
stack<int> s;
vector<vector<int>> ans;		//scc���� ������ �迭
int dfs(int cur)
{
	id[cur] = seq++;
	int ret = id[cur];
	s.push(cur);
	for (int i = 0; i < list[cur].size(); i++) {
		int next = list[cur][i];
		if (id[next] == 0) {		//�ѹ��� �湮���� �ʾҴٸ�
			ret = min(ret, dfs(next));	//�θ� �� ���� ���� id���� ret�� ����
		}
		else if (fin[next] == 0) {	//�湮���� �� ���� scc�� �ƴ϶��
			ret = min(ret, id[next]);	//�θ� �� ���� ���� id���� ret�� ����
		}
	}
	if (ret == id[cur]) {		//�θ� �� ���� ���� id���� ������ id���� ��ġ�Ѵٸ�
		vector<int> scc;
		while (1) {
			int top = s.top();	//stack���� ���ָ鼭
			fin[top] = 1;
			scc.push_back(top);	//scc�� push
			s.pop();
			if (top == cur) {	//stack���� ������ ������
				break;
			}
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
	return ret;
}
int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (id[i] == 0) dfs(i);
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("-1\n");
	}
}