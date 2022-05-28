#include <iostream>

using namespace std;

int N;
long long dp[10][101];					//각 숫자가 들어갈 수 있는 개수를 저장할 배열

int main()
{
	cin >> N;

	long long cnt = 0;					//총 개수를 저장할 변수

	for (int i = 1; i < 10; i++) {		//N이 1일 때 0을 제외한 각 숫자가 한번씩 들어갈 수 있으므로
		dp[i][1] = 1;					//모두 1로 경신
	}

	for (int i = 2; i <= N; i++) {		//2자릿수 부터 돌면서
		for (int j = 0; j < 10; j++) {
			if (j == 0) {				//0일 때는 1밖에 올 수 없으므로
				dp[j][i] = dp[1][i - 1];
			}
			else if (j == 9) {			//9일 때는 8밖에 올 수 없으므로
				dp[j][i] = dp[8][i - 1];
			}
			else {						//값이 1차이나는 수들의 값을 모두 더해줌
				dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
			}
			dp[j][i] %= 1000000000;		//더해준 값을 1000000000으로 나눈 나머지로 경신
		}
	}

	for (int i = 0; i < 10; i++) {
		cnt += dp[i][N];				//각 숫자마다 올 수 있는 숫자들을 더하고
		cnt %= 1000000000;				//1000000000으로 나눈 나머지로 경신해준다.
	}

	cout << cnt;
}