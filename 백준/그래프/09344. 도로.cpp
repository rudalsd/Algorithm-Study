#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

struct node {
	int u, v, w;
};

bool cmp(node left, node right)
{
	return left.w < right.w;
}

node arr[20000];
int vect[10001];
map<pair<int, int>, bool> visited;

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N, M, p, q;
		scanf("%d %d %d %d", &N, &M, &p, &q);

		//visited.clear();

		for (int i = 1; i <= N; i++) {
			vect[i] = i;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
		}

		sort(arr, arr + M, cmp);

		for (int i = 0; i < M; i++) {
			const int u = arr[i].u;
			const int v = arr[i].v;
			const int w = arr[i].w;

			if (Find(u) != Find(v)) {
				Union(u, v);
				visited[{u, v}] = true;
			}
		}

		if (visited[{p, q}] || visited[{q, p}]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}