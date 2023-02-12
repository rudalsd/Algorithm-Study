#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<pair<int, int>> list[4001];
int visited[4001][3];

struct node {
	int to;
	int dist;
	int speed;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 2; i <= N; i++) {
		visited[i][0] = visited[i][1] = visited[i][2] = 2087654321;
	}
	visited[1][0] = 2087654321;

	for (int i = 0; i < M; i++) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);

		list[a].emplace_back(b, d);
		list[b].emplace_back(a, d);
	}

	priority_queue<node, vector<node>, cmp> pq;

	pq.push({ 1,0,1 });
	pq.push({ 1,0,2 });

	while (!pq.empty()) {
		const int dist = pq.top().dist;
		const int cur = pq.top().to;
		const int speed = pq.top().speed;
		pq.pop();

		if (visited[cur][speed] < dist) continue;
		visited[cur][speed] = dist;

		if (speed == 0) {
			for (auto &next : list[cur]) {
				const int nNode = next.first;
				const int nDist = next.second * 4;

				if (visited[nNode][2] > dist + nDist) {
					visited[nNode][2] = dist + nDist;
					pq.push({ nNode,visited[nNode][2],2 });
				}
			}
		}
		else if (speed == 1) {
			for (auto& next : list[cur]) {
				const int nNode = next.first;
				const int nDist = next.second * 2;

				if (visited[nNode][speed] > dist + nDist) {
					visited[nNode][speed] = dist + nDist;
					pq.push({ nNode,visited[nNode][speed],1 });
				}
			}
			
		}
		else {
			for (auto& next : list[cur]) {
				const int nNode = next.first;
				const int nDist = next.second;

				if (visited[nNode][0] > dist + nDist) {
					visited[nNode][0] = dist + nDist;
					pq.push({ nNode,visited[nNode][0],0 });
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[i][1] < visited[i][2] && visited[i][1] < visited[i][0]) {
			ans++;
		}
	}

	printf("%d", ans);
}