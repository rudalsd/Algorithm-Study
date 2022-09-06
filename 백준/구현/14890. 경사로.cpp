#include<iostream>

using namespace std;

int N, L;
int arr1[100][100];
int arr2[100][100];

bool check(int num, int arr[][100])	//길의 통과 여부 확인
{
	int visited[100] = { 0 };
	for (int i = 0; i < N - 1; i++) {
		if (arr[num][i] - arr[num][i + 1] == 1) {
			if (i >= N - L) return false;
			int temp = arr[num][i + 1];
			for (int j = 0; j < L; j++) {
				if (visited[i + 1 + j] == 1 || temp != arr[num][i + 1 + j]) return false;
				temp = arr[num][i + 1 + j];
				visited[i + 1 + j] = 1;
			}
		}
		else if (arr[num][i] - arr[num][i + 1] > 1) {
			return false;
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		if (arr[num][i] - arr[num][i - 1] == 1) {
			if (i < L) return false;
			int temp = arr[num][i - 1];
			for (int j = 0; j < L; j++) {
				if (visited[i - 1 - j] == 1 || temp != arr[num][i - 1 - j]) return false;
				temp = arr[num][i - 1 - j];
				visited[i - 1 - j] = 1;
			}
		}
		else if (arr[num][i] - arr[num][i - 1] > 1) {
			return false;
		}
	}

	return true;
}

int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			scanf("%d", &num);
			arr1[i][j] = num;
			arr2[j][i] = num;

		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (check(i, arr1)) ans++;
		if (check(i, arr2)) ans++;
	}

	printf("%d", ans);
}