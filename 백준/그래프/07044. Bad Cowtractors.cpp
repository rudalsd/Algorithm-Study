#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int A, B, C;
};

bool cmp(node left, node right)
{
	return left.C > right.C;
}

int N, M;
node arr[20000];
int vect[1001];

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int A, int B)
{
	int pA = Find(A);
	int pB = Find(B);

	vect[pB] = pA;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &arr[i].A, &arr[i].B, &arr[i].C);
	}

	sort(arr, arr + M, cmp);

	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		const int A = arr[i].A;
		const int B = arr[i].B;
		const int C = arr[i].C;

		if (Find(A) != Find(B)) {
			Union(A, B);
			ans += C;
			cnt++;
		}
	}

	if (cnt != N - 1) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
}