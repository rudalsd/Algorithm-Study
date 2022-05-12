#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> prime;

int arr[4000010];

void isPrime()													//�����佺�׳׽��� ü
{
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0)continue;
		for (int j = 2 * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i] != 0) {
			prime.push_back(i);
		}
	}
}

int main()
{
	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	isPrime();

	int sum = prime[0];
	int start = 0;
	int end = 0;
	int cnt = 0;
	while (1) {
		if (sum > N) {											//���� N���� ũ�ٸ� start++
			sum -= prime[start];
			start++;
		}
		else if (sum < N) {										//���� N���� �۴ٸ� end++
			end++;
			if (end == prime.size()) {
				break;
			}
			sum += prime[end];
		}
		else {													//���� N�� ���ٸ� cnt++, end++
			cnt++;
			end++;
			if (end == prime.size()) {
				break;
			}
			sum += prime[end];
		}
	}

	cout << cnt;
}