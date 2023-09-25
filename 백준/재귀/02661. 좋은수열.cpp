#include<iostream>

using namespace std;

int N;
int arr[80];
bool ans = false;

bool check(int N)
{
	bool same = true;

	for (int k = 1; k <= N; k++) {
		for (int i = 0; i <= N - k - k; i++) {
			same = true;
			for (int j = 0; j < k; j++) {
				if (arr[i + j] != arr[i + k + j]) {
					same = false;
					continue;
				}
			}
			if (same) return false;
		}
	}

	return true;
}

void dfs(int level)
{
	if (!check(level)) return;
	if (ans) return;
	if (level == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i];
		}
		ans = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (arr[level - 1] != i) {
			arr[level] = i;
			dfs(level + 1);
			arr[level] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N == 1) cout << 1;
	else dfs(0);
}
