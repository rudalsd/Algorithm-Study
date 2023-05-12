#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long

using namespace std;

struct node {
	int K;
	ll num;
	int w;
};

struct cmp {
	bool operator()(node right, node left) {
		if (left.w == right.w) return left.K < right.K;
		return left.w < right.w;
	}
};

int N, k;
vector<node> seq;

bool cmp2(node left, node right)
{
	if (left.w == right.w) return left.K > right.K;
	return left.w < right.w;
}

int main()
{
	priority_queue<node, vector<node>, cmp> pq;
	queue<pair<ll,int>> q;
	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++) {
		int b;
		ll a;
		scanf("%lld %d", &a, &b);
		q.push({a,b});
	}

	for (int i = 1; i <= k; i++) {
		pq.push({ i,q.front().first,q.front().second });
		q.pop();

		if (q.empty()) break;
	}

	ll ans = 0;

	while (!pq.empty()) {
		const int K = pq.top().K;
		const ll num = pq.top().num;
		const int w = pq.top().w;
		pq.pop();

		seq.push_back({ K,num,w });

		if (!q.empty()) {
			pq.push({ K,q.front().first, q.front().second + w });
			q.pop();
		}
	}

	sort(seq.begin(), seq.end(), cmp2);

	for (ll i = 0; i < seq.size(); i++) {
		ans += seq[i].num * (i + 1);
	}

	printf("%lld", ans);
}