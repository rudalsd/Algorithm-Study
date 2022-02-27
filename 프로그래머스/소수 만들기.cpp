#include <vector>
#include <iostream>

using namespace std;
int sum;
int cnt;
vector<int> nums = { 1, 2, 7, 6, 4 };

int sqrt(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (i * i > num)
			return i - 1;
	}
}

int isPrime(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return 0;
	}

	return 1;
}

void dfs(int level, int x)
{
	if (level == 3)
	{
		if (isPrime(sum) == 1)
			cnt++;
		return;
	}

	for (int i = x; i < nums.size() - 2 + level; i++)
	{
		sum += nums[i];
		dfs(level + 1, i + 1);
		sum -= nums[i];
	}
}

int main()
{
	dfs(0, 0);

	cout << cnt;
}