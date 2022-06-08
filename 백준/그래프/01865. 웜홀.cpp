#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M, W;

struct Node {
	int to;
	int dist;
};

int dist[501];

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M >> W;
		vector<Node> list[501];

		memset(dist, -1, sizeof(dist));

		for (int i = 0; i < M; i++) {
			int S, E, T;
			scanf("%d %d %d", &S, &E, &T);
			list[S].push_back({ E,T });
			list[E].push_back({ S,T });
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			scanf("%d %d %d", &S, &E, &T);
			list[S].push_back({ E,-T });
		}

		int flag = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < list[j].size(); k++) {
					int next = list[j][k].to;
					int nextDist = list[j][k].dist;
					if (dist[next] > nextDist + dist[j]) {	//N번째에도 거리가 줄어들었다면 음의 cycle이 있다는 뜻이므로
						dist[next] = nextDist + dist[j];
						if (i == N) {
							flag = 1;
						}
					}
				}
			}
		}

		if (flag == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}