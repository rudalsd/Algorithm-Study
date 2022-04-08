#include <iostream>

using namespace std;

int train[50010];									//각 칸의 승객 수를 저장할 배열
int arr[50010];										//각 칸까지의 승객 수를 모두 더해 저장한 배열
int dp[4][50010];									//최댓값을 저장할 배열
int main()
{
	int N;
	int smallTrain;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> train[i];
		arr[i] = arr[i - 1] + train[i];				//바로 전의 배열의 값에 지금 칸의 값을 더해서 arr배열에 저장
	}

	cin >> smallTrain;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * smallTrain; j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - smallTrain] + arr[j] - arr[j - smallTrain]);
		}											//바로 전의 칸까지의 최댓값과 
	}												//j-smallTrain 칸까지의 최댓값 + 지금 칸에서 smallTrain값을 뺀 배열까지의 합 중 더 큰 값 저장

	cout << dp[3][N];
}