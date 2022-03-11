#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Battery {
	int y;
	int x;
	int num;
	int C;
	int P;
};

int arr[10][10];
int M, A;
int person[2][101];
int charge[101];
Battery BC[8];
vector<Battery> B[2];
int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };

bool cmp(Battery left, Battery right)
{
	return left.P > right.P;
}

void Check(int y, int x, int num)
{
	for (int i = 0; i < A; i++) {
		int dist = abs(BC[i].y - y) + abs(BC[i].x - x);
		if (dist <= BC[i].C) {
			B[num].push_back(BC[i]);
		}
	}

	sort(B[num].begin(), B[num].end(), cmp);
}

void Simulator()
{

	int x1 = 0, y1 = 0;
	int x2 = 9, y2 = 9;
	for (int m = 0; m <= M; m++) {
		B[0].clear();
		B[1].clear();
		Check(y1, x1, 0);
		Check(y2, x2, 1);
		int max = 0;
		if (B[0].size() > 0 && B[1].size() > 0) {
			for (int i = 0; i < B[0].size(); i++)
			{
				int sum = 0;
				for (int j = 0; j < B[1].size(); j++) {
					if (B[0][i].num == B[1][j].num) {
						sum = B[0][i].P;
					}
					else {
						sum = B[0][i].P + B[1][j].P;
					}

					if (max < sum) {
						max = sum;
					}
				}
			}
			charge[m] = max;
		}
		else if (B[0].size() > 0) {
			charge[m] = B[0][0].P;
		}
		else if (B[1].size() > 0) {
			charge[m] = B[1][0].P;
		}
		else {
			charge[m] = 0;
		}

		y1 = y1 + dy[person[0][m]];
		x1 = x1 + dx[person[0][m]];
		y2 = y2 + dy[person[1][m]];
		x2 = x2 + dx[person[1][m]];
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> A;

		for (int i = 0; i < 101; i++) {
			charge[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			cin >> person[0][i];
		}
		for (int i = 0; i < M; i++) {
			cin >> person[1][i];
		}
		person[0][M] = 0;
		person[1][M] = 0;
		for (int i = 0; i < A; i++) {
			int x, y, C, P;
			cin >> x >> y >> C >> P;
			BC[i] = { y - 1,x - 1,i,C,P };
		}

		Simulator();
		int sum = 0;
		for (int i = 0; i <= M; i++) {
			sum += charge[i];
		}

		cout << "#" << t << " " << sum << endl;
	}
}