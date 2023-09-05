#include<iostream>
#include<string>

using namespace std;

struct node {
	int J, O, I;
};

node sum[1001][1001];
int M, N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 1; i <= M; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++) {
			sum[i][j + 1].J = sum[i][j].J + sum[i - 1][j + 1].J - sum[i - 1][j].J;
			sum[i][j + 1].O = sum[i][j].O + sum[i - 1][j + 1].O - sum[i - 1][j].O;
			sum[i][j + 1].I = sum[i][j].I + sum[i - 1][j + 1].I - sum[i - 1][j].I;
			if (temp[j] == 'J') {
				sum[i][j + 1].J++;
			}
			else if (temp[j] == 'O') {
				sum[i][j + 1].O++;
			}
			else {
				sum[i][j + 1].I++;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		node ans = { 0 };

		ans.J = sum[c][d].J - sum[a - 1][d].J - sum[c][b - 1].J + sum[a - 1][b - 1].J;
		ans.O = sum[c][d].O - sum[a - 1][d].O - sum[c][b - 1].O + sum[a - 1][b - 1].O;
		ans.I = sum[c][d].I - sum[a - 1][d].I - sum[c][b - 1].I + sum[a - 1][b - 1].I;

		cout << ans.J << ' ' << ans.O << ' ' << ans.I << '\n';
	}
}
