#include <iostream>

using namespace std;

int arr[100100];
int N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;
	int resultl, resultr;
	int min = 2022222222;

	int de = -1;

	while (left != right)
	{
		long long tmp = arr[left] + arr[right];
		if (min > abs(tmp)) {
			min = abs(tmp);
			resultl = arr[left];
			resultr = arr[right];
			if (min == 0) {
				break;
			}
		}
		if (tmp > 0) {								//합이 0보다 크면 right-1
			right -= 1;
		}
		else {										//아니라면 left+1
			left += 1;
		}
	}

	cout << resultl << " " << resultr;
}