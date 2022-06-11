#include <iostream>

using namespace std;

int n, m;
long long cost[101][101];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {			//출발지와 도착지가 같을 때 0으로 초기화
		for (int j = 1; j <= n; j++) {		//아니라면 INF로 초기화
			if (i == j) {
				cost[i][j] = 0;
			}
			else {
				cost[i][j] = 99999999999;
			}
		}
	}

	for (int i = 0; i < m; i++) {			//출발지와 도착지가 같은 간선이 여러개일 때
		int a, b, c;						//가장 짧은 거리로 초기화
		scanf("%d %d %d", &a, &b, &c);
		if (cost[a][b] > c) {
			cost[a][b] = c;
		}
	}

	for (int k = 1; k <= n; k++) {			//거쳐가는 노드
		for (int i = 1; i <= n; i++) {		//출발 노드
			for (int j = 1; j <= n; j++) {	//도착 노드
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == 99999999999) {	//한번도 갱신이 되지 않았다면
				cout << 0 << " ";				//갈 수 없으므로 0출력
			}
			else {
				cout << cost[i][j] << " ";
			}
		}
		cout << endl;
	}
}