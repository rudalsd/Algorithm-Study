#include <iostream>

using namespace std;

int N, S;
int arr[100100];

int main()
{
	cin >> N >> S;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] >= S) {
			cout << 1;
			return 0;
		}
	}

	if (sum < S) {
		cout << 0;
		return 0;
	}

	int start, end;
	start = 0;
	end = 1;
	int min = 222222222;
	sum = arr[0] + arr[1];

	while (end < N) {
		if (sum < S) {											//���� ���ϴ� ������ ������ end+1
			end += 1;
			sum += arr[end];
		}
		else {													//���� ���ϴ� ������ ũ�ų� ������ start+1
			if (min > end - start + 1) {
				min = end - start + 1;							//���̰� min���� �۴ٸ� min�� �� ����
			}
			sum -= arr[start];
			start += 1;
		}
	}

	cout << min;
}