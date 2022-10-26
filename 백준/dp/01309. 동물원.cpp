#include<iostream>
#define M 9901

using namespace std;

int N;
int arr[100001];

int main()
{
	scanf("%d", &N);

	arr[0] = 1;
	arr[1] = 3;

	for (int i = 2; i <= N; i++) {
		arr[i] = ((arr[i - 1] * 2) % M + arr[i - 2] % M) % M;
	}

	printf("%d", arr[N]);
}