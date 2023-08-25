#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int N, M, T, D;
int arr[25][25];
int floyd[625][625];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T >> D;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++) {
			if (temp[j] >= 'a') {
				arr[i][j] = temp[j] - 'a' + 26;
			}
			else {
				arr[i][j] = temp[j] - 'A';
			}
		}
	}

	for (int i = 0; i < N * M; i++) {
		for (int j = 0; j < N * M; j++) {
			floyd[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];

				if (yy >= 0 && yy < N && xx >= 0 && xx < M && abs(arr[yy][xx] - arr[i][j]) <= T) {
					if (arr[i][j] < arr[yy][xx]) {
						floyd[M * i + j][M * yy + xx] = (arr[yy][xx] - arr[i][j]) * (arr[yy][xx] - arr[i][j]);
					}
					else {
						floyd[M * i + j][M * yy + xx] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < N * M; i++) {
		for (int j = 0; j < N * M; j++) {
			for (int k = 0; k < N * M; k++) {
				if (j!=k && floyd[j][i] != -1 && floyd[i][k] != -1) {
					if (floyd[j][k] == -1 || floyd[j][k] > floyd[j][i] + floyd[i][k]) {
						floyd[j][k] = floyd[j][i] + floyd[i][k];
					}
				}
			}
		}
	}

	int ans = arr[0][0];

	for (int i = 1; i < N * M; i++) {
		if (floyd[0][i] != -1 && floyd[i][0] != -1 && floyd[i][0] + floyd[0][i] <= D) {
			ans = max(ans, arr[i / M][i % M]);
		}
	}

	cout << ans;
}