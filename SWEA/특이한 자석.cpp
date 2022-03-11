#include <iostream>
#include <cmath>

using namespace std;

int magnet[4][8] = { 0 };
int visited[4] = { 0 };

void rotate(int num, int inDir)
{
	visited[num] = 1;
	if (inDir == 1)
	{
		if (magnet[num][2] != magnet[num + 1][6] && num + 1 < 4 && visited[num + 1] != 1) {
			rotate(num + 1, -1);
		}
		if (magnet[num][6] != magnet[num - 1][2] && num - 1 >= 0 && visited[num - 1] != 1) {
			rotate(num - 1, -1);
		}
		int temp = magnet[num][7];
		for (int i = 7; i >= 1; i--) {
			magnet[num][i] = magnet[num][i - 1];
		}
		magnet[num][0] = temp;
	}
	else {
		if (magnet[num][2] != magnet[num + 1][6] && num + 1 < 4 && visited[num + 1] != 1) {
			rotate(num + 1, 1);
		}
		if (magnet[num][6] != magnet[num - 1][2] && num - 1 >= 0 && visited[num - 1] != 1) {
			rotate(num - 1, 1);
		}
		int temp = magnet[num][0];
		for (int i = 0; i < 7; i++) {
			magnet[num][i] = magnet[num][i + 1];
		}
		magnet[num][7] = temp;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int K;
		cin >> K;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
			int num, dir;
			for (int j = 0; j < 4; j++) {
				visited[j] = 0;
			}
			cin >> num >> dir;
			rotate(num - 1, dir);
		}

		int sum = 0;

		for (int i = 0; i < 4; i++) {
			sum += magnet[i][0] * pow(2, i);
		}

		cout << "#" << t << " " << sum << endl;
	}
}