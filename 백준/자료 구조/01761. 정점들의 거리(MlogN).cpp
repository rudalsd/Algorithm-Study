#include<iostream>			//40ms
#include<vector>

using namespace std;

struct node {
	int to;
	int dist;
};

int N, M;
vector<node> list[40001];		//연결된 노드 저장
int visited[40001];
int parent[40001][16];		//parent[i][j] i번 노드의 2^i번째 부모
int dist[40001][16];		//dist[i][j] i번 노드의 2^i번째 부모까지의 거리
int depth[40001];			//노드의 깊이 배열

void dfs(int cur, int D)	//현재 노드와 깊이
{
	if (visited[cur]) return;
	visited[cur] = 1;
	depth[cur] = D;

	for (int i = 0; i < list[cur].size(); i++) {
		int next = list[cur][i].to;
		int cost = list[cur][i].dist;
		if (visited[next] == 1) continue;
		parent[next][0] = cur;
		dist[next][0] = cost;
		dfs(next, D + 1);
	}
}

int LCA(int start, int end)		//공통 조상 찾기
{
	if (depth[start] > depth[end]) {
		int temp = start;
		start = end;
		end = temp;
	}

	int ret = 0;

	for (int i = 15; i >= 0; i--)	//깊이를 같게 만들기
	{
		int mask = 1 << i;

		if (depth[end] - depth[start] >= mask)
		{
			ret += dist[end][i];
			end = parent[end][i];
		}
	}

	if (start == end) {	//깊이가 같을 때 같은 노드에 있다면
		return ret;
	}

	for (int i = 15; i >= 0; i--) {		//부모가 같다면 최초의 공통 조상이거나 넘었거나
		if (parent[start][i] == parent[end][i]) continue;

		ret += dist[start][i] + dist[end][i];
		start = parent[start][i];
		end = parent[end][i];
	}

	ret += dist[start][0] + dist[end][0];	//start, end는 부모가 같으므로 한 칸 더 올라가야함
	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N - 1; i++) {		//연결된 노드 저장
		int a, b, dist;
		scanf("%d %d %d", &a, &b, &dist);
		list[a].push_back({ b,dist });
		list[b].push_back({ a,dist });
	}

	dfs(1, 1);

	for (int i = 1; i < 16; i++) {		//parent[node][i] node의 2^i번째 부모
		for (int j = 1; j <= N; j++) {
			int preParent = parent[j][i - 1];
			parent[j][i] = parent[preParent][i - 1];

			if (parent[j][i] == 0) continue;

			int preDist = dist[j][i - 1];
			dist[j][i] = preDist + dist[preParent][i - 1];
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}