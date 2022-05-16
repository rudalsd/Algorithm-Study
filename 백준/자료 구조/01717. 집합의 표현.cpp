#include <iostream>

using namespace std;

int vect[1000001];
int n, m;

int Parent(int num)
{
	if (vect[num] == -1) return num;
	int ret = Parent(vect[num]);
	vect[num] = ret;
	return ret;
}

void Union(int a, int b)
{
	int Pa = Parent(a);
	int Pb = Parent(b);
	if (Pa == Pb) return;
	vect[Pb] = Pa;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		vect[i] = -1;

	for (int i = 0; i < m; i++) {
		int num, a, b;
		scanf("%d%d%d", &num, &a, &b);
		if (num == 0) {
			Union(a, b);
		}
		else {
			if (Parent(a) == Parent(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}