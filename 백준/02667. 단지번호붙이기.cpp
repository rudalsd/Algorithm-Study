#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char map[25][26] = { 0 };
int cnt = 0;
int N;

void dfs(int y, int x)
{
	int idx[4][2] = {
		-1,0,
		1,0,
		0,1,
		0,-1
	};
	int yy, xx;
	cnt++;
	map[y][x] = 0;

	for (int i = 0; i < 4; i++)
	{
		yy = y + idx[i][0];
		xx = x + idx[i][1];
		if (yy >= 0 && yy < N && xx >= 0 && xx < N && map[yy][xx] == '1')
		{
			dfs(yy, xx);
		}
	}
}

int main()
{
	cin >> N;
	vector<int>apt;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1')
			{
				dfs(i, j);
				apt.push_back(cnt);
				cnt = 0;
			}
		}
	}
	int len = apt.size();
	cout << len << endl;
	sort(apt.begin(), apt.end());
	for (int i = 0; i < len; i++)
	{
		cout << apt[i] << endl;
	}
}