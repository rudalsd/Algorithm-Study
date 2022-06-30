#include<iostream>
#include<vector>

using namespace std;

int N;
long long M;
int arr[10];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	long long ans = 0;

	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		long long num = 1;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				cnt++;		//몇 개의 소수가 곱해져 있는지
				num *= arr[j];	//소수들을 곱함
			}
		}

		if (cnt % 2 == 1) {
			ans += M / num;		//M을 소수들을 모두 곱한 값으로 나눈 값을 더함
		}
		else {
			ans -= M / num;		//M을 소수들을 모두 곱한 값으로 나눈 값을 뺌
		}
	}

	cout << ans;
}