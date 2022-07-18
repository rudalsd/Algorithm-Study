#include<iostream>		//768ms
#include<vector>
#include<queue>

using namespace std;

struct node {
	int to;
	int dist;
};

struct tree {
	int parent;
	int depth;
	int dist;
};

int N, M;
vector<node> list[40001];		//연결된 노드 저장
int visited[40001];
tree arr[40001];			//부모 노드, 깊이, 거리를 저장할 배열

int main()
{
	cin >> N;

	arr[1] = { 0, 1, 0 };

	for (int i = 0; i < N - 1; i++) {		//연결된 노드 저장
		int a, b, dist;
		scanf("%d %d %d", &a, &b, &dist);
		list[a].push_back({ b,dist });
		list[b].push_back({ a,dist });
	}

	queue<node> q;
	q.push({ 1, 0 });

	while (!q.empty())		//1번 노드의 깊이를 1로 두고 내려갈수록 깊이 +1
	{
		int to = q.front().to;
		q.pop();

		if (visited[to] == 1) continue;
		visited[to] = 1;

		for (int i = 0; i < list[to].size(); i++) {
			int next = list[to][i].to;
			int dist = list[to][i].dist;
			if (visited[next] != 1) {
				arr[next] = { to, arr[to].depth + 1, dist };
				q.push({ next, 0 });
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		int ans = 0;
		scanf("%d %d", &a, &b);
		if (arr[a].depth < arr[b].depth) {			//깊이가 다르다면 깊이 맞춰주기
			while (arr[a].depth != arr[b].depth) {
				ans += arr[b].dist;
				b = arr[b].parent;
			}
		}
		else if (arr[a].depth > arr[b].depth) {
			while (arr[a].depth != arr[b].depth) {
				ans += arr[a].dist;
				a = arr[a].parent;
			}
		}
		//깊이가 같다면
		while (1) {		//부모가 같아질 때까지 올라가기
			if (a == b) {
				break;
			}
			ans += arr[a].dist + arr[b].dist;
			a = arr[a].parent;
			b = arr[b].parent;
		}

		printf("%d\n", ans);
	}
}