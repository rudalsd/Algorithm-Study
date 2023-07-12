#include<iostream>
#include<string>
#include<stack>
#include<set>

using namespace std;

string str;
int arr[200];
set<string> ans;
int visited[11];
int cnt;

void dfs(int limit, int level, int num)
{
	if (level == limit) {
		string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (visited[arr[i]] != 1) {
				temp += str[i];
			}
		}

		ans.insert(temp);
		return;
	}

	for (int i = num; i <= cnt; i++) {
		visited[i] = 1;
		dfs(limit, level + 1, i + 1);
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	stack<int> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			cnt++;
			arr[i] = cnt;
			s.push(cnt);
		}
		else if (str[i] == ')') {
			arr[i] = s.top();
			s.pop();
		}
	}

	for (int i = 1; i <= cnt; i++) {
		dfs(i, 0, 1);
	}

	for (auto& next : ans) {
		cout << next << '\n';
	}
}
