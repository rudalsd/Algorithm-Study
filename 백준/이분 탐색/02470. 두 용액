#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int arr[100000];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	int start = 0;
	int end = N - 1;
	int ans = 2000000001;
	int a = 0;
	int b = N - 1;

	while (start < end) {
		int temp = arr[start] + arr[end];
		if (ans > abs(temp)) {
			ans = abs(temp);
			a = start;
			b = end;
		}

		if (temp > 0) {
			end--;
		}
		else {
			start++;
		}
	}

	printf("%d %d", arr[a], arr[b]);
}