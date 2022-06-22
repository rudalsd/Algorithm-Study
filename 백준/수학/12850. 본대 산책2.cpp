#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

vector<vector<ll>> mat = {		//����Ǿ� ������ 1
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,1,1,0,1,1,0},
	{0,0,0,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};

int D;
ll MOD = 1000000007;
unordered_map<int, vector<vector<ll>>> m;

vector<vector<ll>> multi(vector<vector<ll>> A, vector<vector<ll>> B)	//A, B ��� ��
{
	vector<vector<ll>> ret;
	for (int i = 0; i < 8; i++) {
		vector<ll> tmp;
		for (int j = 0; j < 8; j++) {
			ll sum = 0;
			for (int k = 0; k < 8; k++) {
				sum += A[i][k] * B[k][j];
				sum %= MOD;
			}
			tmp.push_back(sum);
		}
		ret.push_back(tmp);
	}

	return ret;
}

vector<vector<ll>> dfs(int num)		//����� num�� ������ �� �迭
{
	if (m.find(num) != m.end()) {
		return m[num];
	}
	if (num % 2 == 0) {
		return m[num] = multi(dfs(num / 2), dfs(num / 2));
	}
	else {
		return m[num] = multi(dfs(num - 1), dfs(1));
	}
}

int main()
{
	cin >> D;

	m[1] = mat;

	dfs(D);

	cout << m[D][0][0];
}