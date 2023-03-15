#include<iostream>

using namespace std;

struct node {
	int u, v, w;
};

bool cmp(node left, node right)
{
	return left.w < right.w;
}

int N, M;
int ans;
int vect[1001];
pair<int, int> arr[10000];

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

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		ans = 0;

		for (int i = 1; i <= N; i++) {
			vect[i] = i;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
		}

		for (int i = 0; i < M; i++) {
			const int a = arr[i].first;
			const int b = arr[i].second;

			if (Find(a) != Find(b)) {
				Union(a, b);
				ans++;
			}
		}

		printf("%d\n", ans);
	}
}