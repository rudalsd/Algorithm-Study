#include<iostream>
#include<queue>
#include<vector>
#define ll long long
#define INF 9999999999

using namespace std;

struct node {
	int V;
	ll C;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.C < right.C;
	}
};

int N, M, K;
vector<node> list[100001];
ll visited[100001];

int main()
{
	priority_queue<node, vector<node>, cmp> pq;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		visited[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int U, V;
		ll C;
		scanf("%d %d %lld", &U, &V, &C);
		list[V].push_back({ U, C });
	}

	for (int i = 0; i < K; i++) {
		int city;
		scanf("%d", &city);
		pq.push({ city,0 });
		visited[city] = 0;
	}

	while (!pq.empty()) {
		const int V = pq.top().V;
		const ll C = pq.top().C;
		pq.pop();

		if (visited[V] < C) continue;

		for (auto& next : list[V]) {
			if (visited[next.V] > C + next.C) {
				visited[next.V] = C + next.C;
				pq.push({ next.V, C + next.C });
			}
		}
	}

	int city = 0;
	ll ans = 0;

	for (int i = 1; i <= N; i++) {
		if (ans < visited[i]) {
			city = i;
			ans = visited[i];
		}
	}

	printf("%d\n%lld", city, ans);
}