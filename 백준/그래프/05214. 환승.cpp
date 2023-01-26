#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, K, M;
vector<int> list[101001];
int visited[101001];

struct node {
	int cur;
	int cnt;
};

int main()
{
	scanf("%d %d %d", &N, &K, &M);

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int station;
			scanf("%d", &station);
			list[station].push_back(N + i);
			list[N + i].push_back(station);
		}
	}

	queue<node> q;
	q.push({ 1,1 });
	visited[1] = 1;

	while (!q.empty()) {
		const int cur = q.front().cur;
		const int cnt = q.front().cnt;
		q.pop();

		if (cur == N) {
			printf("%d", cnt);
			return 0;
		}

		for (auto next : list[cur]) {
			if (visited[next] != 1) {
				visited[next] = 1;
				if (next > N) {
					q.push({ next, cnt });
				}
				else {
					q.push({ next,cnt + 1 });
				}
			}
		}
	}

	printf("-1");
}