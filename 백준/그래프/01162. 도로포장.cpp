#include<iostream>
#include<queue>
#include<vector>
#define ll long long

using namespace std;

struct node {
	int cur;
	ll dist;
	int K;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int N, M, K;
ll visited[10001][21];
vector<pair<int, ll>> list[10001];

int main()
{
	priority_queue<node, vector<node>, cmp>pq;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			visited[i][j] = 9222222222222222222;
		}
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		ll c;
		scanf("%d %d %lld", &u, &v, &c);
		list[u].push_back({ v,c });
		list[v].push_back({ u,c });
	}

	pq.push({ 1,0,0 });

	while (!pq.empty()) {
		const int cur = pq.top().cur;
		const ll dist = pq.top().dist;
		const int cnt = pq.top().K;
		pq.pop();

		if (visited[cur][cnt] < dist) continue;

		if (cur == N) {
			printf("%lld", dist);
			return 0;
		}

		for (auto& next : list[cur]) {
			const int nextNode = next.first;
			const ll nextDist = next.second;
			if (cnt < K) {
				if (visited[nextNode][cnt + 1] > dist) {
					visited[nextNode][cnt + 1] = dist;
					pq.push({ nextNode,dist,cnt + 1 });
				}
			}
			
			if (visited[nextNode][cnt] > dist + nextDist) {
				visited[nextNode][cnt] = dist + nextDist;
				pq.push({ nextNode,dist + nextDist,cnt });
			}
		}
	}
}