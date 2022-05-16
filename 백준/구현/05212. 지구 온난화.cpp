#include<iostream>

using namespace std;

char map[10][11];
char future[10][11];
int R, C;

void sink(int y, int x)
{
	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	int cnt = 0;
	int yy, xx;

	for (int i = 0; i < 4; i++)
	{
		yy = y + dy[i];
		xx = x + dx[i];

		if (yy >= 0 && yy < R && xx >= 0 && xx < C)
		{
			if (map[yy][xx] == '.')
				cnt++;
		}
		else
			cnt++;
	}
	if (cnt >= 3)
		future[y][x] = '.';
	else
		future[y][x] = map[y][x];
}

int main()
{
	cin >> R >> C;
	int indexYmax = 0;
	int indexYmin = 99;
	int indexXmax = 0;
	int indexXmin = 99;

	for (int i = 0; i < R; i++)
		cin >> map[i];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			sink(i, j);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (future[i][j] == 'X')
			{
				if (i > indexYmax)
					indexYmax = i;
				if (i < indexYmin)
					indexYmin = i;
				if (j > indexXmax)
					indexXmax = j;
				if (j < indexXmin)
					indexXmin = j;
			}
		}
	}

	for (int i = indexYmin; i <= indexYmax; i++)
	{
		for (int j = indexXmin; j <= indexXmax; j++)
		{
			cout << future[i][j];
		}
		cout << endl;
	}
}