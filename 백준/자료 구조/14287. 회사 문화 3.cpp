#include<iostream>
#include<vector>

using namespace std;

int n, m;
int segTree[200000];
int s[100001];
int e[100001];
int cnt = -1;
vector<int> list[100001];

void dfs(int num)
{
	s[num] = ++cnt;

	for (int& next : list[num]) {
		dfs(next);
	}

	e[num] = cnt;
}

void updateTree(int node, int w)
{
	while (node != 0) {
		segTree[node] += w;
		node >>= 1;
	}
}

int getTree(int left, int right)
{
	int ret = 0;

	while (left <= right) {
		if (left % 2 == 1) {
			ret += segTree[left];
			left += 1;
		}
		if (right % 2 == 0) {
			ret += segTree[right];
			right -= 1;
		}

		left >>= 1;
		right >>= 1;
	}

	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int parent;
		scanf("%d", &parent);

		if (parent != -1) {
			list[parent].push_back(i);
		}
	}

	dfs(1);

	for (int j = 0; j < m; j++) {
		int com, i;
		scanf("%d %d", &com, &i);

		if (com == 1) {
			int w;
			scanf("%d", &w);
			updateTree(s[i] + n, w);
		}
		else {
			printf("%d\n", getTree(n + s[i], n + e[i]));
		}
	}
}
