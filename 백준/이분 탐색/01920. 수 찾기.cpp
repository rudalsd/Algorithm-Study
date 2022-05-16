#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];																	//���ڸ� ���� �迭
int N, M;

void output(int N, int num)
{
	int start, end, mid;
	start = 0;
	end = N - 1;

	if (num > arr[N - 1]) {															//�ּڰ����� ã�����ϴ� ���� ���� �� 0���
		printf("0\n");
		return;
	}
	else if (num < arr[0]) {														//�ִ񰪺��� ã�����ϴ� ���� Ŭ �� 0���
		printf("0\n");
		return;
	}
	else {
		while (end - start >= 0)													//start �� end�� �����Ǹ� Ż��
		{
			mid = (start + end) / 2;

			if (arr[mid] == num || arr[start] == num || arr[end] == num) {			//���� ��ġ�ϸ� 1���
				printf("1\n");
				return;
			}
			else if (arr[mid] > num) {												//arr[mid]�� num���� ũ�� end�� mid-1 ����
				end = mid - 1;
			}
			else if (arr[mid] < num) {												//arr[mid]�� num���� ������ start�� mid+1 ����
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