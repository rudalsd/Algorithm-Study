#include<iostream>

using namespace std;

int N;
int vect[300001];

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
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < N - 2; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (Find(a) != Find(b)) {
			Union(a, b);
		}
	}

	for (int i = 2; i <= N; i++) {
		if (Find(1) != Find(i)) {
			printf("1 %d", i);
			return 0;
		}
	}
}
