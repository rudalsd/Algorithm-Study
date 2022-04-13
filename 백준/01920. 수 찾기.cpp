#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];																	//숫자를 답을 배열
int N, M;

void output(int N, int num)
{
	int start, end, mid;
	start = 0;
	end = N - 1;

	if (num > arr[N - 1]) {															//최솟값보다 찾고자하는 수가 작을 때 0출력
		printf("0\n");
		return;
	}
	else if (num < arr[0]) {														//최댓값보다 찾고자하는 수가 클 때 0출력
		printf("0\n");
		return;
	}
	else {
		while (end - start >= 0)													//start 와 end가 교차되면 탈출
		{
			mid = (start + end) / 2;

			if (arr[mid] == num || arr[start] == num || arr[end] == num) {			//수가 일치하면 1출력
				printf("1\n");
				return;
			}
			else if (arr[mid] > num) {												//arr[mid]가 num보다 크면 end에 mid-1 대입
				end = mid - 1;
			}
			else if (arr[mid] < num) {												//arr[mid]가 num보다 작으면 start에 mid+1 대입
				start = mid + 1;
			}
		}
	}
	printf("0\n");
	return;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	scanf("%d", &M);


	int num;

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);

		output(N, num);
	}
}