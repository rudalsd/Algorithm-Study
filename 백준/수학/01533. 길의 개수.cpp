#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#define M 1000003
#define ll long long

using namespace std;

int N, S, E, T;
unordered_map<int, vector<vector<ll>>> m;
vector<vector<ll>> vect(50, vector<ll>(50, 0));

vector<vector<ll>> multi(vector<vector<ll>> a, vector<vector<ll>> b)	//행렬 곱셈
{
	vector<vector<ll>> ret(N * 5, vector<ll>(N * 5, 0));
	for (int i = 0; i < N * 5; i++) {
		for (int j = 0; j < N * 5; j++) {
			int sum = 0;
			for (int k = 0; k < N * 5; k++) {
				sum += ((a[i][k] % M) * (b[k][j] % M)) % M;
				sum %= M;
			}
			ret[i][j] = sum;
		}
	}

	return ret;
}

vector<vector<ll>> conquer(int num)		//분할 정복
{
	if (m.count(num) != 0) return m[num];
	if (num == 1) return vect;
	if (num % 2 == 1) {
		return m[num] = multi(conquer(num - 1), conquer(1));
	}
	else {
		return m[num] = multi(conquer(num / 2), conquer(num / 2));
	}
}

int main()
{
	scanf("%d %d %d %d", &N, &S, &E, &T);

	vector<vector<ll>> ans;

	for (int i = 0; i < N; i++) {		//입력 받은 가중치가 있는 행렬을 가중치가 없는 
		string str;						//행렬로 바꾸기
		cin >> str;
		for (int j = 0; j < N; j++) {
			int num = str[j] - '0';
			if (num > 0) {
				vect[i * 5][j * 5 + num - 1] = 1;
			}
			for (int k = 0; k < 4; k++) {
				vect[j * 5 + k + 1][j * 5 + k] = 1;
			}
		}
	}

	ans = conquer(T);

	printf("%d", ans[(S - 1) * 5][(E - 1) * 5]);
}