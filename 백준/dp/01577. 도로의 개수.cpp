#include<iostream>
#include<map>

using namespace std;

int N, M;
long long arr[101][101];
int dy[2] = { -1,0 };
int dx[2] = { 0,-1 };
int broke[205][205];		//공사 중인 도로 체크

int main()
{
	arr[0][0] = 1;

	scanf("%d %d", &N, &M);

	int num;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		broke[b + d][a + c] = 1;
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k < 2; k++) {
				int yy = i + dy[k];
				int xx = j + dx[k];

				if (yy >= 0 && yy <= M && xx >= 0 && xx <= N) {
					if (broke[yy + i][xx + j] != 1) {
						arr[i][j] += arr[yy][xx];
					}
				}
			}
		}
	}

	printf("%lld", arr[M][N]);
}