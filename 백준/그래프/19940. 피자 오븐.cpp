#include<iostream>
#include<queue>

using namespace std;

int T, N;
int visited[66];

struct node {
	int cur;
	int ans[5] = { 0 };
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		int temp = N / 60;
		N %= 60;

		queue<node> q;
		
		fill(visited, visited + 66, 0);

		q.push({ 0,{temp} });
		visited[0] = 1;

		while (!q.empty()) {
			const int cur = q.front().cur;
			int ans[5] = { 0 };
			for (int i = 0; i < 5; i++) {
				ans[i] = q.front().ans[i];
			}
			q.pop();

			if (cur == N) {
				for (int i = 0; i < 5; i++) {
					cout << ans[i] << ' ';
				}
				cout << '\n';
				break;
			}

			if (cur - 1 >= 0 && visited[max(0, cur - 1)] == 0) {
				visited[cur - 1] = 1;
				q.push({ cur - 1, {ans[0],ans[1],ans[2],ans[3],ans[4] + 1} });
			}

			if (cur + 1 <= 65 && visited[cur + 1] == 0) {
				visited[cur + 1] = 1;
				q.push({ cur + 1, {ans[0],ans[1],ans[2],ans[3] + 1,ans[4]} });
			}

			if (cur - 10 >= 0 && visited[cur - 10] == 0) {
				visited[cur - 10] = 1;
				q.push({ cur - 10, {ans[0],ans[1],ans[2] + 1,ans[3],ans[4]} });
			}

			if (cur + 10 <= 65 && visited[cur + 10] == 0) {
				visited[cur + 10] = 1;
				q.push({ cur + 10, {ans[0],ans[1] + 1,ans[2],ans[3],ans[4]} });
			}

			if (cur + 60 <= 65 && visited[cur + 60] == 0) {
				visited[cur + 60] = 1;
				q.push({ cur + 60, {ans[0] + 1,ans[1],ans[2],ans[3],ans[4]} });
			}
		}
	}
}