#include<iostream>

using namespace std;

long long N, B, C;
long long A[1000000];
long long ans;

int main()
{
	scanf("%lld", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	scanf("%lld %lld", &B, &C);

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if (A[i] > 0) {
			if (A[i] % C == 0) {
				ans += A[i] / C;
			}
			else {
				ans += A[i] / C + 1;
			}
		}
	}

	printf("%lld", ans);
}