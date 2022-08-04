#include<iostream>

using namespace std;

int w, n;
int arr[5000];
int dp[400001];
int dp2[400001];


int main()
{
	scanf("%d %d", &w, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int weight = arr[i] + arr[j];	//먼저 2개씩 더한 값들을 dp에 idx와 함께 저장
			if (dp[weight] == 0) {
				dp[weight] = i;
				dp2[weight] = j;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int weight = w - arr[i] - arr[j];
			if (weight > 400000 || weight < 0) continue;	//불가능한 경우
			if (dp[weight] == i || dp2[weight] == j || dp[weight] == j || dp2[weight] == i || dp[weight] == 0) continue;	//idx가 겹치는 경우
			printf("YES");	//위의 조건이 아니라면 YES 출력
			return 0;
		}
	}

	printf("NO");	//불가능하다면 NO 출력
}