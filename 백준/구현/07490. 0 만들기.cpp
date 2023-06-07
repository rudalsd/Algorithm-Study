#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int N;
int ret = 0;
char box[10];
vector<string> ans;

void dfs(int level, int num, int idx)
{
	if (level == N + 1) {
		if (num != 0) {
			if (box[idx] == '-') {
				ret -= num;
			}
			else {
				ret += num;
			}
		}
		if (ret == 0) {
			string temp;
			for (int i = 1; i <= N; i++) {
				temp += '0' + i;
				temp += box[i];
			}
			ans.push_back(temp);
		}
		if (num != 0) {
			if (box[idx] == '-') {
				ret += num;
			}
			else {
				ret -= num;
			}
		}
		return;
	}

	num = num * 10 + level;

	if (N != level) {
		if (box[idx] == '-') {
			ret -= num;
			box[level] = '+';
			dfs(level + 1, 0, level);
			box[level] = '-';
			dfs(level + 1, 0, level);
			ret += num;
			box[level] = 0;
		}
		else {
			ret += num;
			box[level] = '+';
			dfs(level + 1, 0, level);
			box[level] = '-';
			dfs(level + 1, 0, level);
			ret -= num;
			box[level] = 0;
		}
	}

	box[level] = ' ';
	dfs(level + 1, num, idx);
	box[level] = 0;

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		ans.clear();
		cin >> N;

		dfs(1,0,0);

		sort(ans.begin(), ans.end());

		for (auto& next : ans) {
			cout << next << '\n';
		}

		cout << '\n';
	}
}
