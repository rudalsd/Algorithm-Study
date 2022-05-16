#include <iostream>
#include <string>
using namespace std;

string str1;
string str2;
int dp[1001][1001];													//���� ������ ���̸� �����ϱ� ���� dp�迭
char ans[1001];														//������ ������ �迭

int main()
{
	cin >> str1 >> str2;
	str1 = "0" + str1;												//dp[0][0]�� 0���� �ʱ�ȭ�ϱ� ���ؼ� �տ� 0�� �ٿ��ش�.
	str2 = "0" + str2;

	int a = str1.size();
	int b = str2.size();

	for (int i = 1; i < a; i++) {
		for (int j = 1; j < b; j++) {
			if (str1[i] == str2[j]) {								//���ڰ� ���ٸ� dp[i-1][j-1] + 1 �� dp[i][j]�� ����
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {													//�ƴ϶�� dp[i-1][j], dp[i][j-1] �� �� ū ���� dp[i][j]�� ����
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int i = a - 1;
	int j = b - 1;

	while (1) {
		if (dp[i][j] == dp[i - 1][j]) {								//dp[i][j]�� dp[i-1][j] �Ǵ� dp[i][j-1] �� ���� ���� �ִٸ� ��ǥ ����
			i = i - 1;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j = j - 1;
		}
		else {														//���� ���� ���� ���ٸ� i = i - 1, j = j - 1�� �����ϰ� ans�� ���� �ֱ�
			ans[dp[i][j] - 1] = str1[i];							//���� ���� ���ٴ� �� str1[i] == str2[j]��� ��
			i = i - 1;
			j = j - 1;
		}

		if (dp[i][j] == 0) break;
	}

	cout << dp[a - 1][b - 1] << endl;
	cout << ans;
}