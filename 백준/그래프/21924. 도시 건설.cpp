#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

struct node {
	int a;
	int b;
	ll c;
};

bool cmp(node left, node right)
{
	return left.c < right.c;
}

int N, M;
ll ans;
int vect[100001];
node arr[500000];

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
		scanf("%d %d %lld", &arr[i].a, &arr[i].b, &arr[i].c);
		ans += arr[i].c;
	}

	sort(arr, arr + M, cmp);

	for (int i = 0; i < M; i++) {
		const int a = arr[i].a;
		const int b = arr[i].b;
		const ll c = arr[i].c;

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans -= c;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (Find(1) != Find(i)) {
			printf("-1");
			return 0;
		}
	}

	printf("%lld", ans);
}