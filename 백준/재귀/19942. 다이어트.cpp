#include<iostream>
#include<vector>

using namespace std;

struct food {
	int p, f, s, v, c;
};

int N;
int mp, mf, ms, mv;
food arr[15];
int cost = 987654321;
int tmp[5];
vector<int> ans;
vector<int> bucket;

void dfs(int level, int n)
{
	if (tmp[0] >= mp && tmp[1] >= mf && tmp[2] >= ms && tmp[3] >= mv) {
		if (cost > tmp[4]) {
			cost = tmp[4];
			ans = bucket;
		}
		return;
	}
	if (level == N) {
		return;
	}

	for (int i = n; i < N; i++) {
		tmp[0] += arr[i].p;
		tmp[1] += arr[i].f;
		tmp[2] += arr[i].s;
		tmp[3] += arr[i].v;
		tmp[4] += arr[i].c;
		bucket.push_back(i);
		dfs(level + 1, i + 1);
		tmp[0] -= arr[i].p;
		tmp[1] -= arr[i].f;
		tmp[2] -= arr[i].s;
		tmp[3] -= arr[i].v;
		tmp[4] -= arr[i].c;
		bucket.erase(bucket.end() - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
	}

	dfs(0, 0);

	if (cost == 987654321) {
		cout << -1;
		return 0;
	}

	cout << cost << '\n';

	for (auto& next : ans) {
		cout << next + 1 << ' ';
	}
}
