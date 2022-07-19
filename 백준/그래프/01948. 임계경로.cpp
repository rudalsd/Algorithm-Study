#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	int to;
	int dist;
};

int n, m;
int from, to;
vector<node> list[10001];
vector<node> r_list[10001];
int cnt[10001], dist[10001];
int visited[10001];


int Longest_dist(int from)		//가장 오래걸리는 시간 구하기
{
	queue<node> q;
	q.push({ from, 0 });

	while (!q.empty())
	{
		int cur = q.front().to;
		int cDist = q.front().dist;
		q.pop();

		if (cur == to) {
			return cDist;
		}

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i].to;
			int nDist = list[cur][i].dist;

			cnt[next]--;
			dist[next] = max(dist[next], cDist + nDist);	//다음 노드까지 갈 수 있는 최대 거리

			if (cnt[next] == 0) {	//다음 노드까지 갈 수 있는 모든 방법으로 갔을 때
				q.push({ next,dist[next] });
			}
		}
	}
}

int Find_road(int max)				//최대 거리로 갈 수 있는 도로 찾기
{
	int ret = 0;

	queue<node> q;
	q.push({ to, max });

	while (!q.empty())
	{
		int cur = q.front().to;
		int cDist = q.front().dist;
		q.pop();

		if (visited[cur] == 1) continue;
		visited[cur] = 1;

		for (int i = 0; i < r_list[cur].size(); i++) {
			int next = r_list[cur][i].to;
			int nDist = r_list[cur][i].dist;

			if (cDist - nDist == dist[next]) {
				ret++;
				if (visited[next] != 1) {
					q.push({ next,cDist - nDist });
				}
			}
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		r_list[b].push_back({ a,c });
		cnt[b]++;
	}

	cin >> from >> to;

	int max = Longest_dist(from);
	int cnt = Find_road(max);

	cout << max << endl << cnt;
}