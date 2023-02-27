#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	int h1;
	int h2;
	int k;
};

bool cmp(node left, node right)
{
	return left.k > right.k;
}

int N, M;
int s, e;
node arr[300001];
int vect[100001];

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
	scanf("%d %d", &s, &e);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &arr[i].h1, &arr[i].h2, &arr[i].k);
	}

	int ans = 987654321;

	sort(arr, arr + M, cmp);

	for (int i = 0; i < M; i++) {
		const int h1 = arr[i].h1;
		const int h2 = arr[i].h2;
		const int k = arr[i].k;

		if (Find(h1) != Find(h2)) {
			Union(h1, h2);
			ans = min(ans, k);
		}

		if (Find(s) == Find(e)) {
			printf("%d", ans);
			return 0;
		}
	}

	printf("0");
}