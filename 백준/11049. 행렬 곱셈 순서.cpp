#include <iostream>
#include <cstring>

using namespace std;

int N;

struct Matrix {
	int r;
	int c;
};

Matrix arr[550];
int dp[550][550];																//dp[start][end], start���� end���� �ּڰ��� ������ dp�迭

unsigned int DP(int start, int end)												//start���� end������ �ּ����� return�� DP�Լ�
{
	if (start == end) return 0;													//������ return 0;
	if (dp[start][end] != -1) return dp[start][end];							//�ѹ��̶� �ּڰ��� ã�Ƴ����� return dp[start][end]
	if (end - start == 1) return arr[start].r * arr[start].c * arr[end].c;		//�� ĭ ���̶�� �� �࿭�� �� return

	int Min = 2147483647;														//2^31 -1

	for (int i = start; i <= end - 1; i++) {
		int sum = DP(start, i) + DP(i + 1, end);								//Ư�� ������ �࿭ �� �ּڰ����� ���ϰ�
		sum += arr[start].r * arr[i].c * arr[end].c;							//�� ���� �� ó���� ���� �࿭ ���� ������ ��
		Min = min(sum, Min);													//�ּڰ��� Min�� ����
	}
	dp[start][end] = Min;														//���� �� �ּڰ��� dp[start][end]�� ����
	return Min;
}

int main()
{
	cin >> N;

	memset(dp, -1, 4 * 550 * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i].r, &arr[i].c);
	}

	cout << DP(0, N - 1);
}