#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int A, B, L;
};

bool cmp(node left, node right)
{
	return left.L < right.L;
}

int N, M;
int vect[2001];
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
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &arr[i].A, &arr[i].B, &arr[i].L);
	}

	int ans = 0;

	sort(arr, arr + M, cmp);

	for (int i = 0; i < M; i++) {
		const int A = arr[i].A;
		const int B = arr[i].B;
		const int L = arr[i].L;

		if (Find(A) != Find(B)) {
			Union(A, B);
			ans = max(ans, L);
		}
	}

	printf("%d", ans);
}