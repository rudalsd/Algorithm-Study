#include<iostream>
#include<queue>
#define ll long long

using namespace std;

int N;
int vect[1001];
ll arr[1001][1001];

struct node {
	int from;
	int to;
	ll cost;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.cost < right.cost;
	}
};

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
	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%lld", &arr[i][j]);
			if (i < j) {
				pq.push({ i,j,arr[i][j] });
			}
		}
	}

	ll ans = 0;

	while (!pq.empty()) {
		const int a = pq.top().from;
		const int b = pq.top().to;
		const int cost = pq.top().cost;
		pq.pop();

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += cost;
		}
	}

	printf("%lld", ans);
}