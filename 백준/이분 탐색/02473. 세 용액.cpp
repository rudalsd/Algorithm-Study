#include <iostream>
#include <algorithm>

using namespace std;

long long arr[5010];														//자료형을 맞추기 위해 long long으로 선언
int N;

int main()
{
	cin >> N;
	long long min = 4444444444;												//최댓값이 +-30억이므로 long long으로 선언
	int ans[3];
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++) {										//총 N-2번 루프 돌기
		int start = i + 1;													//start = i+1부터 시작
		int end = N - 1;														//end = N-1부터 시작
		while (end > start) {
			long long sum = arr[start] + arr[end] + arr[i];

			if (min > abs(sum)) {
				min = abs(sum);
				ans[0] = arr[i];
				ans[1] = arr[start];
				ans[2] = arr[end];
			}

			if (sum > 0) {													//합이 0보다 크면 end--
				end -= 1;
			}
			else {															//합이 0보다 작거나 같으면 start++
				start += 1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << " ";
	}
}