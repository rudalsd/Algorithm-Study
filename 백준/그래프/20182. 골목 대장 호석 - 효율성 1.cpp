#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node {
	int cur;
	int cost;
	int shame;
};

int N, M, A, B, C;
int visited[21][100001];
vector<pair<int,int>> list[100001];
int ans = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> A >> B >> C;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 20; j++) {
			visited[j][i] = 987654321;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	queue<node> q;

	q.push({ A,0,0 });

	while (!q.empty()) {
		const int cur = q.front().cur;
		const int cost = q.front().cost;
		const int shame = q.front().shame;
		q.pop();

		if (cur == B) {
			ans = min(ans, shame);
			continue;
		}
		if (shame >= ans) continue;

		if (visited[shame][cur] < cost) continue;
		visited[shame][cur] = cost;

		for (auto& next : list[cur]) {
			int Max = max(shame, next.second);
			if (visited[Max][next.first] > cost + next.second && cost + next.second <= C) {
				visited[Max][next.first] = cost + next.second;
				q.push({ next.first,cost + next.second, Max });
			}
		}
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;
}
