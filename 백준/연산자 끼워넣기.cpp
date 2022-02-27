#include<iostream>

using namespace std;

int arr[100];
char cal[5] = "+-*/";
int visited[4];
int result = 0;
int cnt[4];
int N;
int m = -1111111111, n = 1111111111;

int Calculator(int a, int b, char c)
{
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;
	if (a != 0 && b != 0)
		if (c == '/') return a / b;
}

void dfs(int level)
{
	if (level == N - 1)
	{
		if (m < result)
			m = result;
		if (n > result)
			n = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (visited[i] != cnt[i]) {
			int before = result;
			visited[i]++;
			result = Calculator(result, arr[level + 1], cal[i]);
			dfs(level + 1);
			result = before;
			visited[i]--;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> cnt[i];

	result = arr[0];

	dfs(0);

	cout << m << endl << n;
}