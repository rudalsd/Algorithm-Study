#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> list[50];
int visited[50];
int ans;
int root;

void dfs(int num)
{
	int temp = 0;
	if (visited[num]) return;
	visited[num] = 1;

	for (auto& next : list[num]) {
		if (visited[next] != 1) {
			dfs(next);
			temp++;
		}
	}

	if (temp == 0) ans++;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		if (num != -1) {
			list[num].push_back(i);
		}
		else {
			root = i;
		}
	}

	int del;
	scanf("%d", &del);

	dfs(del);

	ans = 0;

	dfs(root);

	printf("%d", ans);
}