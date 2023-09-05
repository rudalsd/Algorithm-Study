#include<iostream>
#include<queue>
#include<vector>
#define ll long long

using namespace std;

int V, E;
vector<pair<int, int>> list[10001];
int arr[10];
ll dist[10];
int start;
ll visited[10001];

int dijkstra(int s, int e)
{
	fill(visited, visited + V + 1, 11111111111);
	visited[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({ 0,s });

	while (!pq.empty()) {
		const int cur = pq.top().second;
		const int dist = pq.top().first;
		pq.pop();

		if (cur == e) {
			return dist;
		}

		if (visited[cur] < dist) continue;
		visited[cur] = dist;

		for (auto& next : list[cur]) {
			if (visited[next.second] > dist + next.first) {
				visited[next.second] = dist + next.first;
				pq.push({ visited[next.second], next.second });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		list[u].push_back({ w,v });
		list[v].push_back({ w,u });
	}

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	cin >> start;

	int cnt = 1;

	for (int i = 0; i < 9; i++) {
		int next = dijkstra(arr[i], arr[i + cnt]);
		while (next == -1) {
			dist[i + cnt] = -1;
			cnt++;
			if (i + cnt == 10) break;
			next = dijkstra(arr[i], arr[i + cnt]);
		}
		if (i + cnt == 10) break;
		dist[i + cnt] = dist[i] + dijkstra(arr[i], arr[i + cnt]);
		i = i + cnt - 1;
		cnt = 1;
	}

	dijkstra(start, 0);
	int ans = 111111;

	for (int i = 0; i < 10; i++) {
		if (visited[arr[i]] <= dist[i]) {
			ans = min(ans, arr[i]);
		}
	}

	if (ans == 111111) cout << -1;
	else cout << ans;
}
