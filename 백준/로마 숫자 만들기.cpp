#include<iostream>

using namespace std;

int limitlevel;
int arr[4] = { 1,5,10,50 };
int cnt = 0;
int sum = 0;
int bucket[1001];

void dfs(int idx, int level)
{
	if (level == limitlevel)
	{
		if (bucket[sum] != 1)
		{
			bucket[sum]++;
			cnt++;
		}
		return;
	}

	for (int i = idx; i < 4; i++)
	{
		sum += arr[i];
		dfs(i, level + 1);
		sum -= arr[i];
	}
}

int main()
{
	cin >> limitlevel;

	dfs(0, 0);

	cout << cnt;
}