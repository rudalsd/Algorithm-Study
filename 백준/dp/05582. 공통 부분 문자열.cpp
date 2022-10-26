#include<iostream>
#include<string>

using namespace std;

int arr[4001][4001];
int ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string str[2];

	cin >> str[0] >> str[1];

	str[0] = '1' + str[0];
	str[1] = '1' + str[1];

	for (int i = 1; i < str[0].size(); i++) {
		for (int j = 1; j < str[1].size(); j++) {
			if (str[0][i] == str[1][j]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
				ans = max(ans, arr[i][j]);
			}
		}
	}

	printf("%d", ans);
}