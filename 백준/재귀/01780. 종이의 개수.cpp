#include<iostream>
using namespace std;
int N;
int arr[2200][2200];
int ans[3];
void conquer(int y1, int y2, int x1, int x2)
{
	int flag = 0;
	int cur = arr[y1][x1];
	for (int i = y1; i < y2; i++) {		//모두 같은 수인지
		for (int j = x1; j < x2; j++) {
			if (cur != arr[i][j]) {
				flag = 1;
				break;
			}
		}
	}
	int y = (y2 - y1) / 3;
	int x = (x2 - x1) / 3;
	if (flag == 0) {		//같은 수라면
		ans[cur + 1]++;
	}
	else {		//다른 수가 있다면
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				conquer(y1 + y * i, y1 + y * (i + 1), x1 + x * j, x1 + x * (j + 1));
			}
		}
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
	conquer(0, N, 0, N);
	for (int i = 0; i < 3; i++) {
		printf("%d\n", ans[i]);
	}
}