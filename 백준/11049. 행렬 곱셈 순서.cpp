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
	int Min = 2147483647;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		cin >> arr[i].r >> arr[i].c;
	}

	for (int i = 0; i < N - 1; i++) {
		int sum = DP(0, i) + DP(i + 1, N - 1);										//��� ������ �̺��ؼ� �� ������ �ּڰ��� sum�� �ְ�,
		sum += arr[0].r * arr[i].c * arr[N - 1].c;								//ó���� �� �࿭�� ���� sum�� ���� ��
		Min = min(sum, Min);													//�ּڰ��� Min�� ����
	}

	cout << Min;
}