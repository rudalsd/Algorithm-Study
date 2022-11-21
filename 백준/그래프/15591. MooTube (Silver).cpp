#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int N, Q;
vector<pair<int, int>> list[5001];
int visited[5001];


int bfs(int k, int v)
{
	queue<pair<int, int>> q;
	q.push({ v,987654321 });
	memset(visited, 0, 4 * (N + 1));

	int ret = 0;
	visited[v] = 1;

	while (!q.empty()) {
		const int cur = q.front().first;
		const int usado = q.front().second;
		q.pop();

		for (auto next : list[cur]) {
			const int temp = min(usado, next.second);

			if (visited[next.first] != 1) {
				visited[next.first] = 1;
				if (temp >= k) {
					ret++;
				}
				else {	//유사도가 k보다 작은 값이 하나라도 있다면 이후 모두 낮기 때문에
					continue;
				}

				q.push({ next.first, temp });
			}
		}
	}

	return ret;
}

int main()
{
	scanf("%d %d", &N, &Q);

	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		list[p].emplace_back(q, r);
		list[q].emplace_back(p, r);
	}

	for (int i = 0; i < Q; i++) {
		int k, v;
		scanf("%d %d", &k, &v);

		printf("%d\n", bfs(k, v));
	}
}