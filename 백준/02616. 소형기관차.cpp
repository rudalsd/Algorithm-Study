#include <iostream>

using namespace std;

int train[50010];									//�� ĭ�� �°� ���� ������ �迭
int arr[50010];										//�� ĭ������ �°� ���� ��� ���� ������ �迭
int dp[4][50010];									//�ִ��� ������ �迭
int main()
{
	int N;
	int smallTrain;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> train[i];
		arr[i] = arr[i - 1] + train[i];				//�ٷ� ���� �迭�� ���� ���� ĭ�� ���� ���ؼ� arr�迭�� ����
	}

	cin >> smallTrain;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * smallTrain; j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - smallTrain] + arr[j] - arr[j - smallTrain]);
		}											//�ٷ� ���� ĭ������ �ִ񰪰� 
	}												//j-smallTrain ĭ������ �ִ� + ���� ĭ���� smallTrain���� �� �迭������ �� �� �� ū �� ����

	cout << dp[3][N];
}