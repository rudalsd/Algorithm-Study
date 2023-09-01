#include<iostream>

using namespace std;

int n, x, y;
int arr[25];
int visited[13];
int ans;

void dfs(int level)
{
	if (level == 2 * n + 1) {
		ans++;
		return;
	}
	if (arr[level]) dfs(level + 1);

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && level + i + 1 <= 2 * n && arr[level] == 0 && arr[level + i + 1] == 0) {
			visited[i] = 1;
			arr[level] = i;
			arr[level + i + 1] = i;
			dfs(level + 1);
			visited[i] = 0;
			arr[level] = 0;
			arr[level + i + 1] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> x >> y;

	arr[x] = arr[y] = y - x - 1;
	visited[y - x - 1] = 1;

	dfs(1);

	cout << ans;
}
