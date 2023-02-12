#include<iostream>
#include<queue>

using namespace std;

int N, M, k;
int arr[10001];
int vect[10001];

int Find(int n)
{
	if (vect[n] == n) return n;
	return vect[n] = Find(vect[n]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	scanf("%d %d %d", &N, &M, &k);
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		pq.push({ arr[i], i });
		vect[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int v, w;
		scanf("%d %d", &v, &w);
		if (Find(v) != Find(w)) {
			Union(v, w);
		}
	}

	int ans = 0;

	while (!pq.empty()) {
		const int cost = pq.top().first;
		const int cur = pq.top().second;
		pq.pop();

		if (Find(cur) != 0) {
			Union(0, cur);
			ans += cost;
		}
	}

	if (ans > k) {
		printf("Oh no");
	}
	else {
		printf("%d", ans);
	}
}