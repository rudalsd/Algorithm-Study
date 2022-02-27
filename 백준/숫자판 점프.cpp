#include<iostream>

using namespace std;

int arr[5][5];
int bucket[999999];
int a;
int cnt;

int pow(int x, int y)
{
	int num = 1;
	if (y == 0)
		return 1;
	for (int i = 0; i < y; i++)
	{
		num *= x;
	}
	return num;
}

void dfs(int level, int y, int x)
{
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0, 0, -1, 1 };
	int yy, xx;
	if (level == 6)
	{
		if (bucket[a] == 0)
		{
			bucket[a]++;
			cnt++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		yy = y + dy[i];
		xx = x + dx[i];
		if (yy >= 0 && yy < 5 && xx >= 0 && xx < 5)
		{
			a += pow(10, 5 - level) * arr[y][x];
			dfs(level + 1, yy, xx);
			a -= pow(10, 5 - level) * arr[y][x];
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(0, i, j);

	cout << cnt;
}