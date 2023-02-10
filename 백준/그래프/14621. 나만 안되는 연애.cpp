#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int u;
	int v;
	int d;
};

bool cmp(node left, node right)
{
	return left.d < right.d;
}

int N, M;
char univ[1001];
int vect[1001];
node arr[10000];

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
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		getchar();
		scanf("%c", &univ[i]);
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].d);
	}

	sort(arr, arr + M, cmp);

	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		const int u = arr[i].u;
		const int v = arr[i].v;
		const int d = arr[i].d;

		if (Find(u) != Find(v) && univ[u] != univ[v]) {
			Union(u, v);
			ans += d;
			cnt++;
		}
	}

	if (cnt == N - 1) {
		printf("%d", ans);
		return 0;
	}

	printf("-1");
}