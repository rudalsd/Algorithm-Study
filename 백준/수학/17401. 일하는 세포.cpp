#include<iostream>
#include<vector>
#include<unordered_map>

#define ll long long
#define M 1000000007

using namespace std;

int T, N, D;

vector<vector<int>> all(21, vector<int>(21, 0));	//모든 행렬을 곱한 행렬
unordered_map<int, vector<vector<int>>> m;		//메모제이션

vector<vector<int>> matrix(vector<vector<int>> arr1, vector<vector<int>> arr2)	//행렬 곱
{
	vector<vector<int>> ret(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ll sum = 0;
			for (int k = 1; k <= N; k++) {
				sum += (((ll)arr1[i][k] % M) * ((ll)arr2[k][j] % M)) % M;
				sum %= M;
			}
			ret[i][j] = sum % M;
		}
	}

	return ret;
}

vector<vector<int>> conquer(int num)		//분할 정복
{
	if (num == 1) {
		return all;
	}
	if (!m[num].empty()) {
		return m[num];
	}

	if (num % 2 == 0) {
		return m[num] = matrix(conquer(num / 2), conquer(num / 2));
	}
	else {
		return m[num] = matrix(conquer(num - 1), conquer(1));
	}
}

int main()
{
	scanf("%d %d %d", &T, &N, &D);

	vector<vector<int>> remain(N + 1, vector<int>(N + 1, 0));	//나머지 행렬들의 곱
	vector<vector<int>> ans(N + 1, vector<int>(N + 1, 0));		//답

	for (int i = 1; i <= N; i++) {	//단위 행렬로 초기화
		all[i][i] = 1;
		ans[i][i] = 1;
	}

	int d = D % T;	//남은 행렬들의 수

	for (int i = 0; i < T; i++) {
		int m, a, b, c;
		scanf("%d", &m);
		vector<vector<int>> temp(N + 1, vector<int>(N + 1, 0));

		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b, &c);
			temp[a][b] = c;	//i번 째 행렬
		}
		if (i == d) {	//나머지 행렬
			remain = all;
		}
		all = matrix(all, temp);
	}

	if (D / T != 0) {	//모든 행렬들이 곱해진 행렬이 곱해지는 횟수
		ans = conquer(D / T);

	}

	ans = matrix(ans, remain);


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}