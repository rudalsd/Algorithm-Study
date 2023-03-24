#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

int N, M;
ll K;
int cost[1000001];
bool isEdge[1000001];
int vect[1000001];

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	cost[pa] = cost[pb] = min(cost[pa], cost[pb]);
	vect[pb] = pa;
}

int main()
{
	scanf("%d %d %lld", &N, &M, &K);

	if (M <= 1) {
		printf("YES");
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
		scanf("%d", &cost[i]);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a != N || b != 1) {
			if (a > b) {
				swap(a, b);
			}
		}

		isEdge[a] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (!isEdge[i]) {
			if (i == N) {
				Union(1, N);
			}
			else {
				Union(i + 1, i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (Find(i) != 0) {
			K -= cost[Find(i)];
			Union(0, i);
		}

		if (K < 0) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}