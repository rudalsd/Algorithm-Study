#include<iostream>
#include<queue>
#include<cmath>
#define ll long long

using namespace std;

struct node {
	int from;
	int to;
	double dist;
};

struct cmp {
	bool operator()(node right, node left) {
		return left.dist < right.dist;
	}
};

int N, M;
pair<int, int> arr[1001];
int vect[1001];
priority_queue<node, vector<node>, cmp> pq;

int Find(int a)		//부모 찾기
{
	if (vect[a] == a) return a;
	return vect[a] = Find(vect[a]);
}

void Union(int a, int b)	//부모 합치기
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

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	for (int i = 1; i <= N - 1; i++) {		//모든 점 간의 거리를 기준으로 pq에 넣기
		for (int j = i + 1; j <= N; j++) {
			ll x1 = arr[i].first;
			ll x2 = arr[j].first;
			ll y1 = arr[i].second;
			ll y2 = arr[j].second;
			double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			pq.push({ i,j,dist });
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (Find(a) != Find(b)) {
			Union(a, b);
		}
	}

	double ans = 0;

	while (!pq.empty()) {
		int a = pq.top().from;
		int b = pq.top().to;
		double dist = pq.top().dist;
		pq.pop();

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans += dist;
		}
	}

	printf("%.2f", ans);
}