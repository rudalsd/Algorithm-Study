#include <iostream>

#define MOD 10007

using namespace std;

int comb[53][53];
int N;

int main()
{
	for (int i = 0; i < 53; i++) {			//iCj의 조합을 dp를 활용해서 미리 구해 놓음
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				comb[i][j] = 1;
			}
			else if (j == 1) {
				comb[i][j] = i;
			}
			else {
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
			}
		}
	}

	cin >> N;
	int ans = 0;

	for (int i = 1; i <= N / 4; i++) {	//포함 배제의 원리
		if (i % 2 == 1) {		//포카드 조합이 홀수일 때
			ans += (comb[13][i] * comb[52 - 4 * i][N - 4 * i]) % MOD;
		}
		else {					//포카드 조합이 짝수일 때
			ans -= (comb[13][i] * comb[52 - 4 * i][N - 4 * i]) % MOD;
		}
		ans = (ans + MOD) % MOD;
	}

	cout << ans;
}