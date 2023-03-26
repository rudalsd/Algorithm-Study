#include<iostream>

using namespace std;

int N;
int arr[100000];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int start = 0;
	int end = N - 1;
	int ans = 987654321;

	while (start < end) {
		int temp = arr[start] + arr[end];

		if (temp > 0) {
			end--;
		}
		else if(temp < 0) {
			start++;
		}
		else {
			ans = 0;
			break;
		}

		if (abs(ans) > abs(temp)) {
			ans = temp;
		}
	}

	printf("%d", ans);
}