#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> list[100001];
int ans;
int last;
bool flag = false;

int checkEnd(int cur)
{
	int end;
	int left = list[cur][0];
	int right = list[cur][1];

	if (left != -1) end = checkEnd(left);

	end = cur;

	if (right != -1) end = checkEnd(right);

	return end;
}

void dfs(int cur)
{
	int left = list[cur][0];
	int right = list[cur][1];

	if (left != -1) {
		dfs(left);
		ans++;
	}

	if (right != -1) {
		dfs(right);
		ans++;
	}
	
	if (last == cur) flag = true;
	if (flag) return;

	ans++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		list[a].push_back(b);
		list[a].push_back(c);
	}

	last = checkEnd(1);

	dfs(1);

	cout << ans;
}
