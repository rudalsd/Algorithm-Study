#include<iostream>

using namespace std;

int N, M;
int vect[2001];
int enemy[2001];

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
		int A, B;
		scanf("%d %d", &A, &B);

		if (Find(A) == Find(B)) {
			printf("0");
			return 0;
		}

		if (enemy[A] == 0) {
			enemy[A] = B;
		}
		else {
			Union(Find(enemy[A]), B);
		}

		if (enemy[B] == 0) {
			enemy[B] = A;
		}
		else {
			Union(Find(enemy[B]), A);
		}
	}

	printf("1");
}