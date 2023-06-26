#include<iostream>

using namespace std;

int N;
int bucket[10];
int cnt = -1;

void dfs(int level, int limit)
{
	if (cnt >= N) return;
	if (level == 0) {
		cnt++;
		if (cnt == N) {
			for (int i = limit - 1; i >= 0; i--) {
				cout << bucket[i];
			}
		}
		return;
	}

	for (int i = level - 1; i < 10; i++) {
		if (level != limit) {
			if (bucket[level] > i) {
				bucket[level - 1] = i;
				dfs(level - 1, limit);
				bucket[level - 1] = 0;
			}
			else {
				return;
			}
		}
		else {
			bucket[level - 1] = i;
			dfs(level - 1, limit);
			bucket[level - 1] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N > 1022) cout << -1;

	for (int i = 1; i <= 10; i++) {
		dfs(i, i);
		if (cnt >= N) break;
	}

	int de = -1;
}
