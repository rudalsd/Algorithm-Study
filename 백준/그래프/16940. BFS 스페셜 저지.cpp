#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N;
vector<int> list[100001];
int visited[100001];
int arr[100001];
int parent[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;

		list[u].push_back(v);
		list[v].push_back(u);
	}

	queue<pair<int, int>> q;

	q.push({ 1,1 });

	while (!q.empty()) {
		const int cur = q.front().first;
		const int cnt = q.front().second;
		q.pop();

		visited[cur] = cnt;

		for (auto next : list[cur]) {
			if (visited[next] == 0) {
				parent[next] = cur;
				visited[next] = cnt + 1;
				q.push({ next,cnt + 1 });
			}
		}
	}

	int temp = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num] = i;

		if ((i == 0 && num != 1) || arr[parent[num]] < arr[parent[temp]] || visited[num] < visited[temp]) {
			cout << 0;
			return 0;
		}
		
		temp = num;
	}

	cout << 1;
}
