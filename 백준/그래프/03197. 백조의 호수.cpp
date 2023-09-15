#include<iostream>
#include<queue>

using namespace std;

int R, C;
int r, c;
char arr[1500][1501];
int visited[1500][1500];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<pair<int, int>> swan, water, tmpW, tmpS;
bool Find = false;

void BFSwater()
{
	while (!water.empty()) {
		const int r = water.front().first;
		const int c = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			const int rr = r + dr[i];
			const int cc = c + dc[i];

			if (rr >= 0 && rr < R && cc >= 0 && cc < C) {
				if (arr[rr][cc] == 'X') {
					tmpW.push({ rr,cc });
					arr[rr][cc] = '.';
				}
			}
		}
	}
}

void BFSswan()
{
	while (!swan.empty() && Find == false) {
		const int r = swan.front().first;
		const int c = swan.front().second;
		swan.pop();

		for (int i = 0; i < 4; i++) {
			const int rr = r + dr[i];
			const int cc = c + dc[i];

			if (rr >= 0 && rr < R && cc >= 0 && cc < C && visited[rr][cc] == 0) {
				visited[rr][cc] = 1;
				if (arr[rr][cc] == '.') {
					swan.push({ rr,cc });
				}
				else if (arr[rr][cc] == 'X') {
					tmpS.push({ rr,cc });
					arr[rr][cc] = '.';
				}
				else if (arr[rr][cc] == 'L') {
					Find = true;
					break;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	

	for (int i = 0; i < R; i++) {
		cin >> arr[i];
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != 'X') {
				water.push({ i,j });
			}
			if (arr[i][j] == 'L') {
				r = i;
				c = j;
			}
		}
	}

	swan.push({ r,c });
	visited[r][c] = 1;

	int ans = 0;

	while (1) {
		BFSswan();
		if (Find == true) {
			cout << ans;
			return 0;
		}
		BFSwater();
		ans++;

		water = tmpW;
		swan = tmpS;

		tmpW = queue<pair<int, int>>();
		tmpS = queue<pair<int, int>>();
	}
}