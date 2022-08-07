#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int to;
	int dist;
};

int n;
int energy[100001];
vector<node> list[100001];
int visited[100001];
int arr[100001][17];
int dist[100001][17];
int H;

void dfs(int cur)	//그래프 그리기
{
	if (visited[cur] == 1) return;
	visited[cur] = 1;

	for (auto next : list[cur]) {
		if (visited[next.to] == 1) continue;
		arr[next.to][0] = cur;
		dist[next.to][0] = next.dist;
		dfs(next.to);
	}
}

void makeTree()		//트리 만들기
{
	for (int i = 1; i < H; i++) {		//순서 중요!!!
		for (int j = 2; j <= n; j++) {
			int next = arr[j][i - 1];
			if (arr[next][i - 1] == 0) continue;
			arr[j][i] = arr[next][i - 1];
			dist[j][i] = dist[next][i - 1] + dist[j][i - 1];
		}
	}
}

int getRomm(int cur)	//최종 도달 방 찾기
{
	int ret = cur;
	int E = energy[cur];
	for (int i = H - 1; i >= 0; i--) {
		if (arr[ret][i] != 0 && dist[ret][i] <= E) {
			E -= dist[ret][i];		//순서 중요!!!
			ret = arr[ret][i];
		}
		if (ret == 1 || E == 0) break;
	}

	return ret;
}

int main()
{
	scanf("%d", &n);
	H = ceil(log2(n));

	for (int i = 1; i <= n; i++) {
		scanf("%d", &energy[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].push_back({ b,c });
		list[b].push_back({ a,c });
	}

	dfs(1);

	makeTree();

	for (int i = 1; i <= n; i++) {
		printf("%d\n", getRomm(i));
	}
}