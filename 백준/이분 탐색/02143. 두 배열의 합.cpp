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
			N[A[i] - A[j]]++;										//나올 수 있는 모든 경우의 수를 N map에 저장
		}
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] += B[i - 1];
		for (int j = 0; j < i; j++) {
			M.push_back(B[i] - B[j]);								//나올 수 있는 모든 경우의 수를 M vector에 저장
		}
	}

	long long cnt = 0;

	for (int i = 0; i < M.size(); i++) {
		long long num = T - M[i];
		cnt += N[num];												//합이 T인 경우를 cnt에 모두 +
	}

	cout << cnt;
}