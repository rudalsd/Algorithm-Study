//#include <iostream>
//
//using namespace std;
//
//int N;
//int arr[17][17];
//int dp[3][17][17];			//각 상태를 저장할 dp배열 [state][y][x] state 0:가로 1:세로 2:대각
//
//int main()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	dp[0][1][2] = 1;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (arr[i][j] != 1) {		//파이프가 움직일 수 있을 때만
//				dp[0][i][j] += dp[0][i][j - 1] + dp[2][i][j - 1];	//가로, 대각
//				dp[1][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];	//세로, 대각
//				if (arr[i - 1][j] != 1 && arr[i][j - 1] != 1) {
//					for (int k = 0; k < 3; k++) {
//						dp[2][i][j] += dp[k][i - 1][j - 1];		//가로, 세로, 대각
//					}
//				}
//			}
//		}
//	}
//
//	int ans = 0;
//	for (int i = 0; i < 3; i++) {
//		ans += dp[i][N][N];
//	}
//
//	cout << ans;
//}

#include <iostream>

using namespace std;

int N;
int arr[16][16];
int dp[3][16][16];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

void dfs(int state, int y, int x)
{
	if (dp[state][y][x] != -1) return;

	int cur = 0;

	if (state != 1 && arr[y][x + 1] == 0 && x + 1 < N) {
		dfs(0, y, x + 1);
		cur += dp[0][y][x + 1];
	}

	if (state != 0 && arr[y + 1][x] == 0 && y + 1 < N) {
		dfs(1, y + 1, x);
		cur += dp[1][y + 1][x];
	}

	bool flag = true;

	for (int i = 0; i < 3; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (arr[yy][xx] != 0) {
			flag = false;
			break;
		}
	}

	if (flag && x + 1 < N && y + 1 < N) {
		dfs(2, y + 1, x + 1);
		cur += dp[2][y + 1][x + 1];
	}

	dp[state][y][x] = cur;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			for (int k = 0; k < 3; k++) {
				if (i == N - 1 && j == N - 1) {
					dp[k][i][j] = 1;
				}
				else {
					dp[k][i][j] = -1;
				}
			}
		}
	}

	dfs(0, 0, 1);

	cout << dp[0][0][1];
}