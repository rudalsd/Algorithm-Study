#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct node {
	int cur, idx;
	char parent;
};

int N;
char arr[500001];
vector<int> list[500001];
int visited[500001];
string ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> arr;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	queue<node> q;
	q.push({ 1, 1, '0'});
	visited[1] = 1;
	ans += '0';

	while (!q.empty()) {
		const int cur = q.front().cur;
		const int idx = q.front().idx;
		const char pa = q.front().parent;
		q.pop();

		if (pa != ans[idx - 1]) continue;
		if (idx >= ans.size()) ans += arr[cur - 1];
		else if (ans[idx] < arr[cur - 1]) {
			ans[idx] = arr[cur - 1];
		}

		for (auto& next : list[cur]) {
			if (visited[next] != 1) {
				visited[next] = 1;
				q.push({ next,idx + 1, arr[cur - 1]});
			}
		}
	}

	ans.erase(ans.begin());

	cout << ans;
}
