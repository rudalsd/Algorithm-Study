#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<int> list[100001];	//간선 정보
int parent[100001][18];		//2^i번째 부모
int height[100001];			//각 노드의 높이
int visited[100001];		//방문 여부
int limit;

void dfs(int cur)		//그래프
{
	if (visited[cur] == 1) return;
	visited[cur] = 1;

	for (auto next : list[cur]) {
		if (visited[next] == 0) {
			height[next] = height[cur] + 1;
			parent[next][0] = cur;
			dfs(next);
		}
	}
}

int find(int a, int b)		//LCA 찾기
{
	if (height[a] > height[b]) {	//a가 루트에 더 가깝게
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = limit; i >= 0; i--) {	//높이 맞추기
		int mask = 1 << i;
		if (height[b] - height[a] >= mask) {
			b = parent[b][i];
		}
	}

	if (a == b) return a;	//같은 노드라면 a return

	for (int i = limit; i >= 0; i--) {		//같인 부모 찾기
		if (parent[a][i] == parent[b][i]) continue;

		a = parent[a][i];
		b = parent[b][i];
	}

	return parent[a][0];
}

int main()
{
	scanf("%d", &N);

	limit = ceil(log2(N));

	for (int i = 0; i < N - 1; i++) {	//간선 정보 얻기
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	dfs(1);

	for (int i = 1; i < limit; i++) {	//parent배열 채우기
		for (int j = 1; j <= N; j++) {
			int next = parent[j][i - 1];
			if (next != 0) {
				parent[j][i] = parent[next][i - 1];
			}
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", find(a, b));
	}
}