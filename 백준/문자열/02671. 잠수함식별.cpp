#include<iostream>
#include<string>

using namespace std;

string str;

int check(int cur)
{
	if (str[cur] == '1') {
		int cnt = 0;
		cur++;
		while (1) {
			if (str[cur] == '0') {
				cur++;
				cnt++;
			}
			else break;
		}

		if (cnt < 2) {
			return -1;
		}

		cnt = 0;

		while (1) {
			if (str[cur] == '1') {
				cur++;
				cnt++;
			}
			else break;
		}

		if (cnt > 0) {
			return cur;
		}
		else {
			return -1;
		}
	}
	else {
		if (str[cur + 1] == '1') {
			return cur + 2;
		}
		else if (str[cur + 1] == '0' && str[cur - 1] == '1' && str[cur - 2] == '1') {
			return cur - 1;
		}
	}

	return -1;
}

int main()
{
	cin >> str;

	int cur = 0;

	while (1) {
		if (cur >= str.size()) {
			printf("SUBMARINE");
			return 0;
		}

		cur = check(cur);

		if (cur == -1) {
			printf("NOISE");
			return 0;
		}
	}
}