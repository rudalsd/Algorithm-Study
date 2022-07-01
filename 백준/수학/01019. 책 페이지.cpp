#include<iostream>
#include<string>

using namespace std;

int N;
int cnt[10];

int NtoA(int num)		//num보다 작은 가장 큰 10^n 수
{
	int digit = 1;
	while (1) {
		digit *= 10;
		if (num < digit) {
			return digit / 10;
		}
	}
}

int NtoB(int num)		//num보다 작은 가장 큰 9로 끝나는 수
{
	if (num < 9) {
		return num;
	}
	while (1)
	{
		if (num % 10 == 9) {
			return num;
		}
		num--;
	}
}

void AtoN(int A, int N, int digit)		//A부터 N까지의 수의 1의 자리 숫자의 개수 구하기
{
	if (N < 10) {
		for (int i = A; i <= N; i++) {
			cnt[i] += digit;
		}
		return;
	}
	int B = NtoB(N);
	for (int i = B + 1; i <= N; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			cnt[str[j] - '0'] += digit;
		}
	}

	for (int i = 0; i < 10; i++) {
		cnt[i] += (B / 10 - A / 10 + 1) * digit;
	}

	AtoN(A / 10, B / 10, digit * 10);
}

int main()
{
	cin >> N;

	int A = NtoA(N);
	int B = NtoB(N);

	if (A > B) {
		for (int i = B + 1; i <= N; i++) {
			string str = to_string(i);
			for (int j = 0; j < str.size(); j++) {
				cnt[str[j] - '0']++;
			}
		}
		A /= 10;
		AtoN(A, B, 1);
	}
	else {
		AtoN(A, N, 1);
	}

	while (1)
	{
		if (A == 1) {
			break;
		}
		AtoN(A / 10, A - 1, 1);
		A /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << " ";
	}
}