#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<pair<int, int>> list[1001];
int visited[1001];
vector<pair<int,int>> ans;

struct node {
	int before;
	int cur;
	int cost;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.cost < right.cost;
	}
};

int main()
{
	priority_queue<node, vector<node>, cmp> pq;
	scanf("%d %d", &N, &M);

	fill(visited, visited + N + 1, 987654321);
	visited[1] = 0;

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		list[A].push_back({ B,C });
		list[B].push_back({ A,C });
	}

	pq.push({ 0,1,0 });

	while (!pq.empty()) {
		const int before = pq.top().before;
		const int cur = pq.top().cur;
		const int cost = pq.top().cost;
		pq.pop();

		if (visited[cur] < cost) continue;

		ans.push_back({ before,cur });

		for (auto& next : list[cur]) {
			if (visited[next.first] > cost + next.second) {
				visited[next.first] = cost + next.second;
				pq.push({ cur, next.first, cost + next.second });
			}
		}
	}

	printf("%d\n", ans.size() - 1);

	for (int i = 1; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}