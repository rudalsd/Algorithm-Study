#include <iostream>
#include <algorithm>

using namespace std;

long long arr[5010];														//�ڷ����� ���߱� ���� long long���� ����
int N;

int main()
{
	cin >> N;
	long long min = 4444444444;												//�ִ��� +-30���̹Ƿ� long long���� ����
	int ans[3];
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++) {										//�� N-2�� ���� ����
		int start = i + 1;													//start = i+1���� ����
		int end = N - 1;														//end = N-1���� ����
		while (end > start) {
			long long sum = arr[start] + arr[end] + arr[i];

			if (min > abs(sum)) {
				min = abs(sum);
				ans[0] = arr[i];
				ans[1] = arr[start];
				ans[2] = arr[end];
			}

			if (sum > 0) {													//���� 0���� ũ�� end--
				end -= 1;
			}
			else {															//���� 0���� �۰ų� ������ start++
				start += 1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << " ";
	}
}