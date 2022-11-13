#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int N;
int arr[10001][14];
int level[10001];
vector<int> list[10001];

void dfs(int num, int lv) {
	level[num] = lv;
	for (auto next : list[num]) {
		dfs(next, lv + 1);
	}
}

int find(int A, int B) {
	int ret = 0;

	if (level[A] > level[B]) {
		int temp = A;
		A = B;
		B = temp;
	}

	int size = ceil(log2(N));

	if (level[A] != level[B]) {
		for (int i = size - 1; i >= 0; i--) {
			int next = arr[B][i];
			if (next == 0) continue;
			if (level[A] < level[next]) {
				B = next;
			}
		}

		B = arr[B][0];
	}

	if (A != B) {
		for (int i = size - 1; i >= 0; i--) {
			int pa = arr[A][i];
			int pb = arr[B][i];

			if (pa != pb) {
				A = pa;
				B = pb;
			}
		}

		A = arr[A][0];
	}

	return A;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);

		int size = ceil(log2(N));

		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= N; i++) {
			list[i].clear();
		}

		for (int i = 0; i < N - 1; i++) {
			int A, B;
			scanf("%d %d", &A, &B);

			arr[B][0] = A;
			list[A].push_back(B);
		}

		int root = 0;

		for (int i = 1; i <= N; i++) {
			if (arr[i][0] == 0) {
				root = i;
				break;
			}
		}

		dfs(root, 1);

		for (int i = 1; i < size; i++) {	//Èñ¼Ò ¹è¿­
			for (int j = 1; j <= N; j++) {
				int next = arr[j][i - 1];
				arr[j][i] = arr[next][i - 1];
			}
		}

		int A, B;
		scanf("%d %d", &A, &B);

		printf("%d\n", find(A, B));
	}
}