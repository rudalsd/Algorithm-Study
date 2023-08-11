#include<iostream>

using namespace std;

int N;
int arr[10000][6];
int ans;

int getSum(int n)
{
	int temp = arr[0][n];
	int idx = n;
	int ret = 0;
	int Max = 0;

	for (int i = 0; i < N; i++) {
		Max = 0;

		for (int j = 0; j < 6; j++) {
			if (arr[i][j] == temp) {
				idx = j;
				break;
			}
		}

		if (idx == 0 || idx == 5) {
			for (int j = 0; j < 6; j++) {
				if (j != 0 && j != 5) {
					Max = max(Max, arr[i][j]);
				}
			}

			if (idx == 0) {
				temp = arr[i][5];
			}
			else {
				temp = arr[i][0];
			}
		}
		else if (idx == 1 || idx == 3) {
			for (int j = 0; j < 6; j++) {
				if (j != 1 && j != 3) {
					Max = max(Max, arr[i][j]);
				}
			}

			if (idx == 1) {
				temp = arr[i][3];
			}
			else {
				temp = arr[i][1];
			}
		}
		else {
			for (int j = 0; j < 6; j++) {
				if (j != 2 && j != 4) {
					Max = max(Max, arr[i][j]);
				}
			}

			if (idx == 2) {
				temp = arr[i][4];
			}
			else {
				temp = arr[i][2];
			}
		}

		ret += Max;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 6; i++) {
		ans = max(ans, getSum(i));
	}

	cout << ans;
}