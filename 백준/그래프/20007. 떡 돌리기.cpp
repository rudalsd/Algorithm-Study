#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, X, Y;
vector<pair<int, int>> list[1000];
int visited[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X >> Y;

	fill(visited, visited + N, -1);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		list[A].push_back({ B,C });
		list[B].push_back({ A,C });
	}

	priority_queue<pair<int, int>> pq;

	pq.push({ 0,Y });

	while (!pq.empty()) {
		const int cur = pq.top().second;
		const int cost = pq.top().first;
		pq.pop();

		if (visited[cur] == -1 || visited[cur] >= cost) {
			visited[cur] = cost;
		}

		for (auto& next : list[cur]) {
			int nextCost = next.second;
			int nextNode = next.first;

			if (visited[nextNode] == -1 || visited[nextNode] > cost + nextCost) {
				visited[nextNode] = cost + nextCost;
				pq.push({ cost + nextCost,nextNode });
			}
		}
	}

	sort(visited, visited + N);

	int cur = 0;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i] * 2 > X) {
			cout << -1;
			return 0;
		}
		
		cur += visited[i] * 2;

		if (cur > X) {
			ans++;
			cur = visited[i] * 2;
		}
	}

	cout << ans + 1;
}