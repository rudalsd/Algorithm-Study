#include<iostream>

using namespace std;

int N, M;
int vect[1000001];
int visited[1000001];

int Find(int num) {
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
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		if (Find(x) != Find(y)) {
			for (int j = y; j > x; j--) {
				j = Find(j);
				Union(x, j);
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (visited[Find(i)] == 0) {
			visited[Find(i)] = 1;
			ans++;
		}
	}

	printf("%d", ans);
}
