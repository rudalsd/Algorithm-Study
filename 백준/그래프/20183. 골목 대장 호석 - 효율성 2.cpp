#include<iostream>
#include<queue>
#include<vector>
#define ll long long

using namespace std;

int N, M;
int A, B;
ll C;
vector<pair<int, int>> list[100001];
int s, e;
int ans = -1;
ll visited[100001];

bool dijkstra(int m)
{
	fill(visited, visited + N + 1, 111111111111111);
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

	pq.push({ 0,A });

	while (!pq.empty()) {
		const ll cost = pq.top().first;
		const int cur = pq.top().second;
		pq.pop();

		if (cost > C) continue;

		if (cur == B) {
			return true;
		}

		if (visited[cur] < cost) continue;
		visited[cur] = cost;

		for (auto& next : list[cur]) {
			if (visited[next.second] > cost + next.first && next.first <= m) {
				visited[next.second] = cost + next.first;
				pq.push({ cost + next.first, next.second });
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> A >> B >> C;
	s = 1;

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		list[u].push_back({ w,v });
		list[v].push_back({ w,u });
		e = max(e, w);
	}

	while (s <= e) {
		int m = (s + e) / 2;

		if (dijkstra(m)) {
			ans = m;
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}

	cout << ans;
}
