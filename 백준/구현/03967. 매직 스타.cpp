#include<iostream>
#include<string>
#include<vector>

using namespace std;

string str[5];
char arr[12];
int visited[12];
vector<int> pos;
bool flag = false;

void dfs(int level)
{
	if (flag) return;
	if (arr[1] + arr[2] + arr[3] + arr[4] > 282) return;
	if (arr[0] + arr[2] + arr[5] + arr[7] > 282) return;
	if (arr[0] + arr[3] + arr[6] + arr[10] > 282) return;
	if (arr[7] + arr[8] + arr[9] + arr[10] > 282) return;
	if (arr[1] + arr[5] + arr[8] + arr[11] > 282) return;
	if (arr[4] + arr[6] + arr[9] + arr[11] > 282) return;

	if (level == pos.size()) {
		int cnt = 0;
		flag = true;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				if (str[i][j] != '.') {
					cout << arr[cnt++];
				}
				else {
					cout << str[i][j];
				}
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < 12; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[pos[level]] = i + 'A';
			dfs(level + 1);
			visited[i] = 0;
			arr[pos[level]] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}

	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (str[i][j] != '.') {
				if (str[i][j] == 'x') {
					pos.push_back(cnt++);
				}
				else {
					visited[str[i][j] - 'A'] = 1;
					arr[cnt++] = str[i][j];
				}
			}
		}
	}

	dfs(0);
}