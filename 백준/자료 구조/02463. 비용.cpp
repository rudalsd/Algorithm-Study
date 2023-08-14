#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;

struct edge {
	int u, v, c;
};

int N, M;
edge arr[100000];
int vect[100001];
int cnt[100001];

bool cmp(edge left, edge right)
{
	return left.c > right.c;
}

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = vect[a];
	int pb = vect[b];

	vect[pb] = pa;
	cnt[pa] += cnt[pb];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	ll sum = 0;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		arr[i] = { u,v,c };

		sum += c;
	}

	sort(arr, arr + M, cmp);

	ll ans = 0;

	for (int i = 0; i < M; i++) {
		const int u = arr[i].u;
		const int v = arr[i].v;
		const int c = arr[i].c;

		if (Find(u) != Find(v)) {
			ans += sum * cnt[Find(u)] * cnt[Find(v)];
			Union(u, v);
		}

		sum -= c;
	}

	cout << ans % 1000000000;
}