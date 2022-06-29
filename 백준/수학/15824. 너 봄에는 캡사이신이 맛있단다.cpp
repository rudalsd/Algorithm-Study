#include<iostream>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

int N;
long long arr[300001];
long long comb[300001];
long long ans;

long long Comb(int n)		//���� ������ ���� 2�� n�� ���ϱ�
{
	if (comb[n] != -1) return comb[n];
	if (n % 2 == 0) {
		return comb[n] = ((Comb(n / 2) % MOD) * (Comb(n / 2) % MOD)) % MOD;
	}
	else {
		return comb[n] = ((Comb(n - 1) % MOD) * (Comb(1) % MOD)) % MOD;
	}
}

int main()
{
	cin >> N;
	memset(comb, -1, sizeof(comb));
	comb[0] = 1;
	comb[1] = 2;

	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {		//arr[i]�� �ִ밡 �Ǵ� ������ �������� arr[i]�� �ּҰ� �Ǵ� ������ ������ ����
		ans += ((Comb(i) - Comb(N - i - 1) + MOD) % MOD) * (arr[i] % MOD);	//�ű⿡ arr[i]�� ���� ���� ans�� ����
		ans %= MOD;
	}

	cout << ans;
}