#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

struct node {
	int to;
	int max;
	int min;
};

int N, K;
int H;		//트리의 높이
node arr[100001][18];
vector<vector<node>> list;
int visited[100001];
int h[100001];	//노드의 높이

void dfs(int cur)	//arr[cur][0] 채우기
{
	if (visited[cur] == 1) return;
	visited[cur] = 1;

	for (auto next : list[cur])
	{
		if (visited[next.to] != 1) {
			arr[next.to][0] = { cur, next.max, next.min };
			h[next.to] = h[cur] + 1;
			dfs(next.to);
		}
	}
}

void makeTree()		//트리 만들기
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++) {
			auto next = arr[j][i - 1];
			if (arr[next.to][i - 1].to != 0) {
				int Max = max(next.max, arr[next.to][i - 1].max);
				int Min = min(next.min, arr[next.to][i - 1].min);
				arr[j][i] = { arr[next.to][i - 1].to, Max, Min };
			}
		}
	}
}

void Dist(int a, int b)	//a, b 사이의 가장 긴 도로와 짧은 도로 길이 구하기
{
	if (h[a] > h[b]) {	//a가 트리의 더 위에 있도록
		int temp = a;
		a = b;
		b = temp;
	}

	int Min = 987654321;
	int Max = 0;

	if (h[a] != h[b]) {	//높이가 다르다면 맞춰주기
		for (int i = H; i >= 0; i--) {
			int mask = 1 << i;
			if (h[b] - h[a] >= mask) {
				Min = min(Min, arr[b][i].min);
				Max = max(Max, arr[b][i].max);
				b = arr[b][i].to;
			}
			if (h[a] == h[b]) break;
		}
	}

	if (a != b) {	//같은 높이일 때 서로 다른 숫자면
		for (int i = H; i >= 0; i--) {
			if (arr[a][i].to == arr[b][i].to || arr[a][i].to == 0 || arr[b][i].to == 0) continue;
			Max = max(Max, max(arr[a][i].max, arr[b][i].max));
			Min = min(Min, min(arr[a][i].min, arr[b][i].min));
			a = arr[a][i].to;
			b = arr[b][i].to;
		}

		Max = max(Max, max(arr[a][0].max, arr[b][0].max));
		Min = min(Min, min(arr[a][0].min, arr[b][0].min));
	}

	printf("%d %d\n", Min, Max);
}

int main()
{
	scanf("%d", &N);

	H = ceil(log2(N));
	list.resize(N + 1);
	h[1] = 1;

	for (int i = 0; i < N - 1; i++) {
		int a, b, dist;
		scanf("%d %d %d", &a, &b, &dist);

		list[a].push_back({ b,dist,dist });
		list[b].push_back({ a,dist,dist });
	}

	dfs(1);
	makeTree();

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Dist(a, b);
	}
}