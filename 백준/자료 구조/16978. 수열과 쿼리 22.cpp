#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

struct query2 {
	int k, i, j;
	int seq;
};

struct cmp {
	bool operator()(query2 left, query2 right) {
		return left.k < right.k;
	}
};

int N, M;
ll segTree[200000];
vector<pair<int, int>> query;
vector<query2> queryArr;
ll ans[100000];
int arr[100001];

void updateTree(int idx, int n)
{
	while (idx) {
		segTree[idx] += n;
		idx >>= 1;
	}
}

ll getTree(int l, int r)
{
	ll ret = 0;

	while (l <= r) {
		if (l & 1) {
			ret += segTree[l];
			l++;
		}
		if (~r & 1) {
			ret += segTree[r];
			r--;
		}
		l >>= 1;
		r >>= 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr[i] = n;
		updateTree(N + i, n);
	}

	cin >> M;
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int i, v;
			cin >> i >> v;
			query.push_back({ i,v });
		}
		else {
			int k, i, j;
			cin >> k >> i >> j;
			queryArr.push_back({ k,i,j,cnt++ });
		}
	}

	sort(queryArr.begin(), queryArr.end(), cmp());

	int cur = 0;

	for (auto& next : queryArr) {
		int k = next.k;
		for (int i = cur; i < k; i++) {
			int a = query[i].first;
			int b = query[i].second;
			updateTree(a + N - 1, b - arr[a-1]);
			arr[a - 1] = b;
		}
		cur = k;

		ans[next.seq] = getTree(N + next.i - 1, N + next.j - 1);
	}

	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << '\n';
	}
}