#include<iostream>
#include<vector>

using namespace std;

vector<int> arr[100001];
int good[100001];
int ans[100001];
int n, m;

void dfs(int num, int w)
{
	if (num == 0) return;

	ans[num] = good[num] + w;

	for (auto& next : arr[num]) {
		dfs(next, good[num] + w);
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int parent;
		scanf("%d", &parent);

		if (parent != -1) {
			arr[parent].push_back(i);
		}
	}

	for (int j = 0; j < m; j++) {
		int i, w;
		scanf("%d %d", &i, &w);

		good[i] += w;
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
}