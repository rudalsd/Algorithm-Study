#include<iostream>

using namespace std;

int N, M;
int arr[201][201];
int longest[201][201];
float ans = 987654321;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {		//각 노드까지 거리 초기화
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 987654321;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int S, E, L;
		scanf("%d %d %d", &S, &E, &L);

		if (arr[S][E] > L) {	//최단거리 저장
			arr[S][E] = L;
			arr[E][S] = L;
		}
		if (longest[S][E] < L) {	//최장거리 저장
			longest[S][E] = L;
			longest[E][S] = L;
		}
	}

	for (int i = 1; i <= N; i++) {	//각각의 노드에서 노드까지 최단거리 갱신
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {	//i번 노드에서 시작했을 때 다 타는데 걸리는 시간 time
		float time = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				float remain = longest[j][k] - (arr[i][j] - arr[i][k]);
				if (remain > 0) {
					time = max(time, arr[i][j] + remain / 2);
				}
			}
		}
		ans = min(time, ans);	//time 중 가장 짧은 시간 저장
	}

	printf("%.1f", ans);
}