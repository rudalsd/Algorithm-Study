#include <iostream>
#include <queue>
#include <vector>

#define INF 2e8

using namespace std;

struct Node {
	int node;
	int cost;
};

long long dist[501];
vector<Node> list[501];

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 2; i <= N; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		list[A].push_back({ B,C });
	}

	int lastUpdate = 0;

	for (int n = 0; n < N; n++) {
		lastUpdate = 0;
		for (int i = 1; i <= N; i++) {
			if (dist[i] == INF) continue;
			for (int j = 0; j < list[i].size(); j++) {
				if (dist[list[i][j].node] > dist[i] + list[i][j].cost) {
					dist[list[i][j].node] = dist[i] + list[i][j].cost;
					lastUpdate = 1;
				}
			}
		}
		if (lastUpdate == 0) break;
	}

	if (lastUpdate == 1) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] != INF) {
				cout << dist[i] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}