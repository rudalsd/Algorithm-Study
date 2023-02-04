#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int cur;
	int cost;
	int max;
};

int N, s, e;
vector<pair<int, int>> list[100001];
int visited[100001];

int main()
{
	scanf("%d %d %d", &N, &s, &e);

	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	queue<node> q;
	q.push({ s,0,0 });
	visited[s] = 1;

	while (!q.empty()) {
		const int cur = q.front().cur;
		const int cost = q.front().cost;
		const int Max = q.front().max;
		q.pop();

		if (cur == e) {
			printf("%d", cost - Max);
			return 0;
		}

		for (auto& next : list[cur]) {
			if (visited[next.first] != 1) {
				visited[next.first] = 1;
				q.push({ next.first, cost + next.second, max(Max, next.second) });
			}
		}
	}
}