#include<iostream>
#include<deque>
#include<string>
#define ll long long

using namespace std;
deque<ll> number;
deque<char> symbol;
ll ans;

ll cal(ll num1, ll num2, char sym)
{
	if (sym == '+') {
		return num1 + num2;
	}
	else if (sym == '-') {
		return num1 - num2;
	}
	else if (sym == '*') {
		return num1 * num2;
	}
	else {
		return num1 / num2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	bool isFirst = false;
	ll num = 0;

	for (int i = 0; i < str.size(); i++) {
		if (i == 0 && str[i] == '-') {
			isFirst = true;
		}
		else if (str[i] >= '0') {
			num = num * 10 + str[i] - '0';
		}
		else {
			if (isFirst) {
				isFirst = false;
				num *= -1;
			}
			number.push_back(num);
			symbol.push_back(str[i]);
			num = 0;
		}
	}
	if (isFirst) {
		isFirst = false;
		num *= -1;
	}
	number.push_back(num);

	if (number.size() == 1) {
		cout << number.front();
		return 0;
	}

	while (1) {
		ll tmp[4] = { 0 };

		if (number.size() == 3) {
			tmp[0] = number.front();
			tmp[3] = number.back();
			number.pop_back();
			number.pop_front();
			tmp[1] = tmp[2] = number.front();
		}
		else if (number.size() == 2) {
			tmp[0] = number.front();
			tmp[1] = number.back();
		}
		else {
			tmp[0] = number.front();
			tmp[3] = number.back();
			number.pop_back();
			number.pop_front();
			tmp[1] = number.front();
			tmp[2] = number.back();
		}

		if (symbol.size() == 1) {
			char sym = symbol.front();
			cout << cal(tmp[0], tmp[1], sym);

			return 0;
		}
		else {
			char sym1 = symbol.front();
			char sym2 = symbol.back();

			if (sym1 == '+' || sym1 == '-') {
				if (sym2 == '*' || sym2 == '/') {
					symbol.pop_back();
					number.pop_back();
					number.push_back(cal(tmp[2], tmp[3], sym2));
					number.push_front(tmp[0]);
				}
				else {
					ll num1 = cal(tmp[0], tmp[1], sym1);
					ll num2 = cal(tmp[2], tmp[3], sym2);

					if (num1 >= num2) {
						symbol.pop_front();
						number.pop_front();
						number.push_front(cal(tmp[0], tmp[1], sym1));
						number.push_back(tmp[3]);
					}
					else {
						symbol.pop_back();
						number.pop_back();
						number.push_back(cal(tmp[2], tmp[3], sym2));
						number.push_front(tmp[0]);
					}
				}
			}
			else if (sym1 == '*' || sym1 == '/') {
				if (sym2 == '+' || sym2 == '-') {
					symbol.pop_front();
					number.pop_front();
					number.push_front(cal(tmp[0], tmp[1], sym1));
					number.push_back(tmp[3]);
				}
				else {
					ll num1 = cal(tmp[0], tmp[1], sym1);
					ll num2 = cal(tmp[2], tmp[3], sym2);

					if (num1 >= num2) {
						symbol.pop_front();
						number.pop_front();
						number.push_front(cal(tmp[0], tmp[1], sym1));
						number.push_back(tmp[3]);
					}
					else {
						symbol.pop_back();
						number.pop_back();
						number.push_back(cal(tmp[2], tmp[3], sym2));
						number.push_front(tmp[0]);
					}
				}
			}
		}
	}
}