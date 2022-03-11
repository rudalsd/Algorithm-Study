#include <iostream>

using namespace std;

int N, X;

struct bridge {
	int height = 0;
	int use = 0;
};

int Check(bridge arr[])
{
	int before = arr[0].height;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (before == arr[i].height) {
			cnt++;
		}
		else if (before < arr[i].height) {
			if (arr[i].height - before > 1) {
				return 0;
			}
			if (X > cnt) {
				return 0;
			}
			cnt = 1;
			for (int j = i - X; j < i; j++) {
				arr[j].use = 1;
			}
		}
		else if (arr[i].use == 1) {
			cnt = 0;
		}
		else {
			cnt = 1;
		}
		before = arr[i].height;
	}
	cnt = 0;
	before = arr[N - 1].height;
	for (int i = N - 1; i >= 0; i--) {
		if (before == arr[i].height && arr[i].height && arr[i].use != 1) {
			cnt++;
		}
		else if (before < arr[i].height) {
			if (arr[i].height - before > 1) {
				return 0;
			}
			if (X > cnt) {
				return 0;
			}
			cnt = 1;
		}
		else if (arr[i].use == 1) {
			cnt = 0;
		}
		else {
			cnt = 1;
		}
		before = arr[i].height;
	}

	return 1;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> X;
		bridge arr[20][20] = { 0 };
		bridge after[20][20] = { 0 };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j].height;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				after[j][N - 1 - i] = arr[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (Check(arr[i])) {
				cnt++;
			}
			if (Check(after[i])) {
				cnt++;
			}
		}


		cout << "#" << t << " " << cnt << endl;
	}
}