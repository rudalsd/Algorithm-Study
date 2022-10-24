#include<iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	long long arr[101] = { 0 };

	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;

	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);

		printf("%lld\n", arr[N]);
	}
}