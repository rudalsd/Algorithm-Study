#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int> list[101];
int group[101];
int arr[101][101];
pair<int,int> ans[101];
int cnt;

void dfs(int cur)
{
	for (auto& next : list[cur]) {
		if (group[next] == 0) {
			group[next] = cnt;
			dfs(next);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (group[i] == 0) {
			group[i] = ++cnt;
			dfs(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][i] != 0 && arr[i][k] != 0) {
					if (arr[j][k] == 0 || arr[j][k] > arr[j][i] + arr[i][k]) {
						arr[j][k] = arr[j][i] + arr[i][k];
					}
				}
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		ans[i].second = 987654321;
	}

	for (int i = 1; i <= N; i++) {
		int Max = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				Max = max(Max, arr[i][j]);
			}
		}

		if (ans[group[i]].second > Max) {
			ans[group[i]].second = Max;
			ans[group[i]].first = i;
		}
	}

	cout << cnt << '\n';

	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++) {
		cout << ans[i].first << '\n';
	}
}
