#include <iostream>
#include <string>
using namespace std;

string str1;
string str2;
int dp[1001][1001];													//최장 수열의 길이를 저장하기 위한 dp배열
char ans[1001];														//정답을 저장할 배열

int main()
{
	cin >> str1 >> str2;
	str1 = "0" + str1;												//dp[0][0]을 0으로 초기화하기 위해서 앞에 0을 붙여준다.
	str2 = "0" + str2;

	int a = str1.size();
	int b = str2.size();

	for (int i = 1; i < a; i++) {
		for (int j = 1; j < b; j++) {
			if (str1[i] == str2[j]) {								//문자가 같다면 dp[i-1][j-1] + 1 를 dp[i][j]에 저장
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {													//아니라면 dp[i-1][j], dp[i][j-1] 중 더 큰 수를 dp[i][j]에 저장
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int i = a - 1;
	int j = b - 1;

	while (1) {
		if (dp[i][j] == dp[i - 1][j]) {								//dp[i][j]가 dp[i-1][j] 또는 dp[i][j-1] 중 같은 수가 있다면 좌표 갱신
			i = i - 1;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j = j - 1;
		}
		else {														//만약 같은 수가 없다면 i = i - 1, j = j - 1로 갱신하고 ans에 문자 넣기
			ans[dp[i][j] - 1] = str1[i];							//같은 수가 없다는 건 str1[i] == str2[j]라는 뜻
			i = i - 1;
			j = j - 1;
		}

		if (dp[i][j] == 0) break;
	}

	cout << dp[a - 1][b - 1] << endl;
	cout << ans;
}