#include<iostream>
#define ll long long

using namespace std;

int N;
ll arr[100];
ll ans[100];
int visited[100];
bool flag = false;

void dfs(int level)
{
	if (flag) return;

	if (level == N) {
		for (int i = 0; i < N; i++) {
			cout << ans[i] << ' ';
		}

		flag = true;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0 && (ans[level-1] * 2 == arr[i] || (ans[level-1] % 3 == 0 && ans[level - 1] / 3 == arr[i]))) {
			visited[i] = 1;
			ans[level] = arr[i];
			dfs(level + 1);
			visited[i] = 0;
			ans[level] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		ans[0] = arr[i];
		dfs(1);
		ans[0] = 0;
		visited[i] = 0;
	}
}
