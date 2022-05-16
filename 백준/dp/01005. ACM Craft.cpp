#include <iostream>
#include <vector>

using namespace std;

int arr[1100];
int dp[1100];
int N, K, X, Y, W;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> K;
		vector<int> list[1100];
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			list[i].push_back(0);													//선행 건물이 없을 경우를 대비해 0번 건물을 모든 건물에 추가
			dp[i] = -1;																//건물이 지어진 적이 없을 때 -1로 초기화
		}

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			list[Y].push_back(X);													//선행 건물을 list에 push
		}

		cin >> W;

		for (int a = 0; a < N; a++) {
			if (dp[W] != -1) break;													//짓기를 원하는 건물이 지어졌을 때 break
			for (int i = 1; i <= N; i++) {
				if (dp[W] != -1) break;
				int max = 0;
				if (dp[i] == -1) {													//건물이 지어지지 않았을 때 건물이 지어질 최소 시간 구하기
					for (int j = 0; j < list[i].size(); j++) {
						if (dp[list[i][j]] != -1) {
							if (max < dp[list[i][j]]) {								//가장 늦게 지어지는 건물을 max에 대입
								max = dp[list[i][j]];
							}
						}
						else {
							max = -1;
							break;
						}
					}
					if (max != -1) {
						dp[i] = max + arr[i];										//선행 건물이 모두 지어졌을 때 dp에 건물이 지어지는 시간 대입
					}
				}
			}
		}
		cout << dp[W] << endl;
	}
}
