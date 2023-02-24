#include<iostream>
#include<vector>
#include<queue>
#define ll long long

using namespace std;

int N, M;
int arr[100000];
ll visited[100000];
vector<pair<int, ll>> list[100000];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		visited[i] = 11111111111;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		ll t;
		scanf("%d %d %lld", &a, &b, &t);
		list[a].push_back({ b,t });
		list[b].push_back({ a,t });
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	pq.push({ 0,0 });

	while (!pq.empty()) {
		const ll dist = pq.top().first;
		const int cur = pq.top().second;
		pq.pop();

		if (cur == N - 1) {
			printf("%lld", dist);
			return 0;
		}

		if (visited[cur] < dist) continue;
		visited[cur] = dist;

		for (auto& next : list[cur]) {
			if ((arr[next.first] != 1 && visited[next.first] > dist + next.second) || next.first == N - 1) {
				visited[next.first] = next.second + dist;
				pq.push({ visited[next.first], next.first });
			}
		}
	}

	printf("-1");
}