#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long T, n, m;

long long A[1010];
long long B[1010];
unordered_map<long long, long long> N;
vector<long long> M;

int main()
{
	cin >> T >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = 0; j < i; j++) {
			N[A[i] - A[j]]++;										//���� �� �ִ� ��� ����� ���� N map�� ����
		}
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
		for (int j = 0; j < i; j++) {
			M.push_back(B[i] - B[j]);								//���� �� �ִ� ��� ����� ���� M vector�� ����
		}
	}

	long long cnt = 0;

	for (int i = 0; i < M.size(); i++) {
		long long num = T - M[i];
		cnt += N[num];												//���� T�� ��츦 cnt�� ��� +
	}

	cout << cnt;
}