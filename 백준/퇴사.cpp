#include <iostream>

using namespace std;

int day[16];
int money[16];
int N;
int sum;
int m;

void dfs(int cur)
{
	if (cur > N + 1)
		return;

	if (m < sum)
		m = sum;

	for (int i = 1; i <= N; i++) {
		if (cur <= i) {
			sum += money[i];
			int next = i + day[i];
			dfs(next);
			sum -= money[i];
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> day[i] >> money[i];

	dfs(0);

	cout << m;
}