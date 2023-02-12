#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int start;
	int end;
	int width;
};

bool cmp(node left, node right) {
	return left.width > right.width;
}

int p, w, c, v;
node arr[50000];
int vect[1000];

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
	scanf("%d %d %d %d", &p, &w, &c, &v);

	for (int i = 1; i < p; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < w; i++) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		arr[i] = { s,e,w };
	}

	sort(arr, arr + w, cmp);

	int ans = 1000;

	for (int i = 0; i < w; i++) {
		const int a = arr[i].start;
		const int b = arr[i].end;
		const int width = arr[i].width;

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans = min(ans, width);

			if (Find(c) == Find(v)) {
				printf("%d", ans);
				return 0;
			}
		}
	}
}