#include<iostream>
#include<queue>

using namespace std;

int N, M;
int vect[1001];

struct node {
	int a;
	int b;
	int dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
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
	scanf("%d %d", &N, &M);
	priority_queue<node, vector<node>, cmp> pq;

	for (int i = 1; i <= N; i++) {
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pq.push({ a,b,c });
	}

	int ans = 0;

	while (!pq.empty()) {
		const int a = pq.top().a;
		const int b = pq.top().b;
		const int dist = pq.top().dist;
		pq.pop();

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += dist;
		}
	}

	printf("%d", ans);
}