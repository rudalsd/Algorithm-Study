#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
vector<int> list[11];
int ans = 987654321;
int mask;

void check(int num)
{
	int tmp = 0;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (num & 1 << i) {
			for (auto& next : list[i]) {
				tmp |= 1 << next;
			}
			cnt++;
		}
	}

	if (tmp == mask) {
		ans = min(ans, cnt);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			list[i].push_back(tmp);
		}
	}

	mask = pow(2, N + 1) - 2;
	
	for (int i = 1; i < pow(2, M); i++) {
		check(i);
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;
}
