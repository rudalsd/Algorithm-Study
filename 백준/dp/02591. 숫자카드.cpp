#include<iostream>
#include<string>

using namespace std;

int ans[40];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	ans[0] = 1;
	if (str[1] - '0' == 0) {
		ans[1] = 1;
		ans[0] = 0;
	}
	else {
		if ((str[0] - '0') * 10 + str[1] - '0' <= 34) {
			ans[1] = 2;
		}
		else {
			ans[1] = 1;
		}
	}

	for (int i = 2; i < str.size(); i++) {
		if (str[i] - '0' == 0) {
			ans[i] = ans[i - 2];
			ans[i - 1] = 0;
		}
		else {
			if ((str[i - 1] - '0') * 10 + str[i] - '0' <= 34) {
				ans[i] = ans[i - 2] + ans[i - 1];
			}
			else {
				ans[i] = ans[i - 1];
			}
		}
	}

	cout << ans[str.size() - 1];
}