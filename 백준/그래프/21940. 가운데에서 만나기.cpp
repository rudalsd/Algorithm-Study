#include<iostream>
#include<vector>

using namespace std;

int N, M, K;
int arr[201][201];
int C[201];
vector<int> ans;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < M; i++) {
		int A, B, T;
		scanf("%d %d %d", &A, &B, &T);

		arr[A][B] = T;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][i] != 0 && arr[i][k] != 0) {
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}
			}
		}
	}
	
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &C[i]);
	}

	int min = 987654321;

	for (int i = 1; i <= N; i++) {
		int Max = 0;
		for (int j = 0; j < K; j++) {
			Max = max(Max, arr[i][C[j]] + arr[C[j]][i]);
		}
		
		if (min > Max) {
			min = Max;
			ans.clear();
			ans.push_back(i);
		}
		else if (min == Max) {
			ans.push_back(i);
		}
	}

	for (auto& next : ans) {
		printf("%d ", next);
	}
}