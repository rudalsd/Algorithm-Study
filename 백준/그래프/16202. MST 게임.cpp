#include<iostream>

using namespace std;

int N, M, K;
pair<int, int> arr[10001];
int vect[1001];
int Min = 1;
bool zero = false;

int Find(int num)
{
	if (vect[num] == num)return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}

	for (int k = 0; k < K; k++) {
		int ans = 0;
		int temp = 987654321;
		if (zero) {
			printf("0 ");
			continue;
		}
		for (int i = 1; i <= N; i++) {
			vect[i] = i;
		}

		for (int i = Min; i <= M; i++) {
			const int a = arr[i].first;
			const int b = arr[i].second;

			if (Find(a) != Find(b)) {
				Union(a, b);
				ans += i;
				temp = min(temp, i);
			}
		}

		Min = temp + 1;

		for (int i = 2; i <= N; i++) {
			if (Find(1) != Find(i)) {
				printf("0 ");
				zero = true;
				break;
			}
		}

		if (zero != true) {
			printf("%d ", ans);
		}
	}
}