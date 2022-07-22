#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {		//노드의 정보를 저장할 struct
	int to;			//다음 노드
	int dist;		//다음 노드까지의 거리
};

struct cmp {		//priority_queue 비교 연산자
	bool operator()(node right, node left)
	{
		return left.dist < right.dist;
	}
};

int n, m, r;
int item[101];		//각 지역의 아이템 수를 저장할 배열
vector<node> list[101];	//그래프

int main()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {	//모든 지역 탐색
		int cnt = 0;
		priority_queue < node, vector<node>, cmp> pq;
		int visited[101] = { 0 };

		pq.push({ i, 0 });

		while (!pq.empty())
		{
			int to = pq.top().to;
			int dist = pq.top().dist;
			pq.pop();

			if (visited[to] == 1 || dist > m) continue;	//방문했거나 거리가 멀면 continue
			visited[to] = 1;
			cnt += item[to];

			for (int i = 0; i < list[to].size(); i++) {
				int next = list[to][i].to;
				int nDist = list[to][i].dist;
				if (visited[next] == 0) {
					pq.push({ next, nDist + dist });
				}
			}
		}

		if (ans < cnt) {
			ans = cnt;
		}
	}

	cout << ans;
}