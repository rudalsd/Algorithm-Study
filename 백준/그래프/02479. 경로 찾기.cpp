#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int N, K;
vector<int> list[1001];
int visited[1001];
string str[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> str[i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < K; k++) {
				if (str[i][k] != str[j][k]) {
					cnt++;
				}
				if (cnt > 1) break;
			}
			if (cnt == 1) {
				list[i].push_back(j);
				list[j].push_back(i);
			}
		}
	}

	queue<pair<int, vector<int>>>q;

	int A, B;
	cin >> A >> B;

	q.push({ A,{} });
	visited[A] = 1;

	while (!q.empty()) {
		const int cur = q.front().first;
		vector<int> route = q.front().second;
		q.pop();

		route.push_back(cur);

		if (cur == B) {
			for (auto& next : route) {
				cout << next << ' ';
			}
			return 0;
		}

		for (auto& next : list[cur]) {
			if (visited[next] != 1) {
				visited[next] = 1;
				q.push({ next,route });
			}
		}
	}

	cout << -1;
}