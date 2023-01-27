#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int u;
	int v;
	int w;
};

struct cmp {
	bool operator()(node left, node right) {
		return left.w < right.w;
	}
};

int N, M, K;
int vect[1001];
node arr[100001];

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
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < K; i++) {
		int plant;
		scanf("%d", &plant);
		vect[plant] = 0;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
	}

	sort(arr, arr + M, cmp());

	int ans = 0;

	for(int i=0;i<M;i++){
		const int u = arr[i].u;
		const int v = arr[i].v;
		const int w = arr[i].w;

		if (Find(u) != Find(v)) {
			Union(u, v);
			ans += w;
		}
	}

	printf("%d", ans);
}