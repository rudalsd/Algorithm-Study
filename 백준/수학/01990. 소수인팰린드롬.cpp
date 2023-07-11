#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a, b;
int prime[10000001];

bool check(int num)
{
	string temp = to_string(num);
	string temp2 = temp;
	reverse(temp.begin(), temp.end());

	if (temp != temp2) return false;
	return true;
}

bool isPrime(int num)
{
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	b = min(b, 10000000);

	for (int i = a; i <= b; i++) {
		if (check(i)) {
			if (isPrime(i)) {
				cout << i << '\n';
			}
		}
	}

	cout << -1 << '\n';
}
