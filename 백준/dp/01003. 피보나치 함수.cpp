#include<iostream>

using namespace std;

struct cnt {
	int zero;
	int one;
};

cnt arr[41];

int main()
{
	arr[0] = { 1,0 };
	arr[1] = { 0, 1 };
	for (int i = 2; i <= 40; i++) {
		arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
		arr[i].one = arr[i - 1].one + arr[i - 2].one;
	}
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;

		scanf("%d", &N);

		printf("%d %d\n", arr[N].zero, arr[N].one);
	}
}