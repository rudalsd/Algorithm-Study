#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[101];
int visited[101];
int ans[101];
vector<int> box;
int cnt;

void dfs(int cur)
{
	if (ans[cur] == 1) return;

	if (visited[cur] == 1) {
		bool flag = false;
		for (auto& next : box) {
			if (next == cur) {
				flag = true;
			}
			if (flag == true) {
				ans[next] = 1;
				cnt++;
			}
		}
		box.clear();
		return;
	}
	box.push_back(cur);

	visited[cur] = 1;
	dfs(arr[cur]);
	
	return;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i] != 1) {
			fill(visited, visited + N + 1, 0);
			dfs(i);
		}
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= N; i++) {
		if (ans[i] == 1) {
			printf("%d\n", i);
		}
	}
}