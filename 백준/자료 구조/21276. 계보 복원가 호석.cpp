#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int N, M;
map<string, int> m;
string str[1000];
int cnt[1000];
map<string, vector<string>> child;
vector<int> list[1000];
vector<string> parent;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		m[str[i]] = i;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		string tmp[2];
		cin >> tmp[0] >> tmp[1];
		cnt[m[tmp[0]]]++;
		list[m[tmp[1]]].push_back(m[tmp[0]]);
	}

	queue<int> q;

	for (int i = 0; i < N; i++) {
		if (cnt[i] == 0) {
			q.push(i);
			parent.push_back(str[i]);
		}
	}

	while (!q.empty()) {
		const int cur = q.front();
		q.pop();

		for (auto& next : list[cur]) {
			cnt[next]--;
			if (cnt[next] == 0) {
				child[str[cur]].push_back(str[next]);
				q.push(next);
			}
		}
	}

	sort(parent.begin(), parent.end());

	cout << parent.size() << '\n';

	for (auto& next : parent) {
		cout << next << ' ';
	}

	cout << '\n';

	sort(str, str + N);

	for (int i = 0; i < N; i++) {
		cout << str[i] << ' ' << child[str[i]].size() << ' ';
		sort(child[str[i]].begin(), child[str[i]].end());
		for (auto& next : child[str[i]]) {
			cout << next << ' ';
		}
		cout << '\n';
	}
}