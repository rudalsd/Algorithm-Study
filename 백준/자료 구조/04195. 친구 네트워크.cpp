#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int vect[200001];
int rel[200001];
unordered_map<string, int> m;

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
	rel[pa] += rel[pb];
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int F;
		int cnt = 1;
		m.clear();
		scanf("%d", &F);

		for (int i = 1; i <= F * 2; i++) {
			vect[i] = i;
			rel[i] = 1;
		}

		for (int i = 0; i < F; i++) {
			char A[21];
			char B[21];
			scanf("%s %s", A, B);

			if (m.count(A) == 0) {
				m[A] = cnt++;
			}
			if (m.count(B) == 0) {
				m[B] = cnt++;
			}

			int a = m[A];
			int b = m[B];

			if (Find(a) != Find(b)) {
				Union(a, b);
			}

			printf("%d\n", rel[Find(a)]);
		}
	}
}