#include<iostream>

using namespace std;

int T;
int arr[10001];

int main()
{
	scanf("%d", &T);

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	for (int i = 4; i <= 10000; i++) {
		arr[i] = arr[i - 3] + i / 2 + 1;
	}

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		printf("%d\n", arr[n]);
	}
}