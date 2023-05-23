#include<iostream>

using namespace std;

int N, M;
int vect[100001];
int ans;
int visited[100001];

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
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (Find(a) != Find(b)) {
			Union(a, b);
		}
		else {
			ans++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[Find(i)] == 0) {
			visited[Find(i)] = 1;
			ans++;
		}
	}

	printf("%d", ans - 1);
}
