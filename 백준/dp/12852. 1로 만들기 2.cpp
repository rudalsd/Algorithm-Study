#include <iostream>

using namespace std;

struct Node {
	int cnt = 0;
	int node = 0;
};

Node dp[3000010];

int main()
{
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		dp[i] = { -1,0 };
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {															//현재 항에 1 더하기
				if (dp[i + 1].cnt == -1) {
					dp[i + 1] = { dp[i].cnt + 1, i };
				}
				else {
					if (dp[i + 1].cnt > dp[i].cnt + 1) {
						dp[i + 1] = { dp[i].cnt + 1, i };
					}
				}
			}
			else if (j == 1) {														//현재 항에 2 곱하기
				if (dp[i * 2].cnt == -1) {
					dp[i * 2] = { dp[i].cnt + 1, i };
				}
				else {
					if (dp[i * 2].cnt > dp[i].cnt + 1) {
						dp[i * 2] = { dp[i].cnt + 1, i };
					}
				}
			}
			else {																	//현재 항에 3 곱하기
				if (dp[i * 3].cnt == -1) {
					dp[i * 3] = { dp[i].cnt + 1, i };
				}
				else {
					if (dp[i * 3].cnt > dp[i].cnt + 1) {
						dp[i * 3] = { dp[i].cnt + 1, i };
					}
				}
			}
		}
	}

	cout << dp[N].cnt << endl;
	cout << N << " ";

	while (1) {
		N = dp[N].node;
		if (N == 0) break;
		cout << N << " ";
	}
}