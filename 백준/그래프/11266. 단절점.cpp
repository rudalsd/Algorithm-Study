#include<iostream>
#include<vector>

using namespace std;

int V, E;
vector<int> list[10001];
int id[10001];
int ans[10001];
int cur = 1;

int dfs(int node, bool root)
{
	id[node] = cur++;
	int ret = id[node];
	int child = 0;

	for (auto next : list[node]) {
		if (id[next]) {	//이미 방문했다면
			ret = min(ret, id[next]);
			continue;
		}
		child++;	//자식의 개수

		int minId = dfs(next, false);	//갈수 있는 노드 중 가장 id값이 낮은 노드

		if (!root && minId >= id[node]) {	//루트가 아니고 자신보다 더 낮은 id값을 가진 노드로 가지 못할 때
			ans[node] = 1;
		}

		ret = min(ret, minId);
	}

	if (root && child > 1) {
		ans[node] = 1;
	}

	return ret;
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++) {		//그래프 만들기
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 1; i <= V; i++) {	//방문하지 않은 노드라면
		if (!id[i]) {
			dfs(i, true);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= V; i++) {	//단절점의 개수
		if (ans[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 1; i <= V; i++) {	//단절점 출력
		if (ans[i] == 1) printf("%d ", i);
	}
}