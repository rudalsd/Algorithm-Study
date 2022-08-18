#include<iostream>

using namespace std;

int N;
int arr[20][20];
int box[20];
int ans = 987654321;

void dfs(int level, int n)
{
	if (level == N / 2) {
		int a, b;
		a = b = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {	//같은 팀이면 값 더하기
				if (box[i] == 1 && box[j] == 1) {
					a += arr[i][j];
				}
				else if (box[i] == 0 && box[j] == 0) {
					b += arr[i][j];
				}
			}
		}
		ans = min(ans, abs(a - b));
		return;
	}


	for (int i = n; i < N; i++) {	//20 C 10
		box[i] = 1;
		dfs(level + 1, i + 1);
		box[i] = 0;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d", ans);
}