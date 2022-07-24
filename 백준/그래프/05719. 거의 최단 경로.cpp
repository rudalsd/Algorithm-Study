#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct node {
	int to;
	int dist;
};

struct cmp {
	bool operator()(node right, node left)
	{
		return left.dist < right.dist;
	}
};

int N, M, S, D;
vector<vector<node>> list;		//그래프
vector<vector<int>> link;		//link[i] = {j} j->i까지의 거리가 최단거리
int routed[500][500];			//지울 간선
int dijk[500];			//각 노드까지의 최단 거리


int dijkstra()		//최단 거리를 구하는 함수
{
	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ S,0 });

	for (int i = 0; i < N; i++) {
		dijk[i] = 987654321;
	}

	dijk[S] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().to;
		int dist = pq.top().dist;
		pq.pop();

		if (dijk[cur] < dist) continue;	//최단 거리가 아니라면

		for (int i = 0; i < list[cur].size(); i++) {
			int next = list[cur][i].to;
			int nDist = list[cur][i].dist;

			if (routed[cur][next] == 1) {	//사라진 간선이라면
				continue;
			}

			if (dijk[next] == dist + nDist) {	//최단거리와 같다면
				link[next].push_back(cur);
			}
			else if (dijk[next] > dist + nDist) {	//최단 거리가 갱신된다면
				link[next].clear();
				link[next].push_back(cur);

				dijk[next] = dist + nDist;
				pq.push({ next,dist + nDist });
			}
		}
	}

	return dijk[D] == 987654321 ? -1 : dijk[D];
}

void remove(int cur)
{
	for (int i = 0; i < link[cur].size(); i++) {	//현재 노드에 연결된 최단 거리 노드
		int node = link[cur][i];
		if (routed[node][cur] != 1) {
			routed[node][cur] = 1;		//경로에서 제거

			remove(node);			//연결된 노드에 또 연결된 최단 거리 노드들 제거
		}
	}
}

int main()
{
	while (1) {
		scanf("%d %d", &N, &M);
		memset(routed, 0, sizeof(routed));

		list.clear();
		list.resize(N);
		link.clear();
		link.resize(N);

		if (N == 0) {
			break;
		}

		scanf("%d %d", &S, &D);

		for (int i = 0; i < M; i++) {
			int U, V, P;
			scanf("%d %d %d", &U, &V, &P);
			list[U].push_back({ V,P });
		}

		dijkstra();
		remove(D);
		printf("%d\n", dijkstra());
	}
}