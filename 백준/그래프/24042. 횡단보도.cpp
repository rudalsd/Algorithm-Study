#include<iostream>
#include<queue>
#include<vector>
#define ll long long

using namespace std;

struct node {
	int cur;
	ll cnt;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.cnt < right.cnt;
	}
};

int N, M;
ll visited[100001];
vector<pair<int, ll>> list[700001];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		visited[i] = 1844674407370955161;
	}

	for (ll i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].emplace_back(b, i);
		list[b].emplace_back(a, i);
	}

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ 1,0 });

	while (!pq.empty()) {
		const int cur = pq.top().cur;
		const ll cnt = pq.top().cnt;
		pq.pop();

		if (cur == N) {
			printf("%lld", cnt);
			return 0;
		}

		for (const auto& next : list[cur]) {
			if ((cnt % M) - 1 > next.second) {	//현재보다 앞의 상태
				ll ndist = cnt + M - cnt % M + next.second + 1;
				if (visited[next.first] > ndist) {
					visited[next.first] = ndist;
					pq.push({ next.first, ndist });
				}
			}
			else if ((cnt % M) - 1 < next.second) {	//현재보다 뒤의 상태
				ll ndist = cnt - cnt % M + next.second + 1;
				if (visited[next.first] > ndist) {
					visited[next.first] = ndist;
					pq.push({ next.first, ndist });
				}
			}
		}
	}
}