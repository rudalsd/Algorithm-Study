#include<iostream>

using namespace std;

int n, k, m;
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

	vect[pb] = pa;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			vect[i] = i;
		}

		scanf("%d", &k);

		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			Union(a, b);
		}

		scanf("%d", &m);

		printf("Scenario %d:\n", t);

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (Find(a) != Find(b)) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}

		printf("\n");
	}
}
