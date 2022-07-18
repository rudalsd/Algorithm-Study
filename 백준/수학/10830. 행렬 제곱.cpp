#include<iostream>
#include<vector>

#define ll long long

using namespace std;

int N;
ll B;

vector<vector<int>> A;		//행렬 A
vector<vector<int>> ans;	//정답 행렬

vector<vector<int>> gop(vector<vector<int>> a, vector<vector<int>> b)		//행렬 곱
{
	vector<vector<int>> ret;
	ret.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum += (a[i][k] * b[k][j]) % 1000;
				sum %= 1000;
			}
			ret[i].push_back(sum);
		}
	}

	return ret;
}

vector<vector<int>> conquer(ll num)		//분할 정복
{
	if (num == 1) {
		return A;
	}

	if (num % 2 == 0) {
		vector<vector<int>> temp = conquer(num / 2);
		return gop(temp, temp);
	}
	else {
		return gop(conquer(num - 1), conquer(1));
	}
}

int main()
{
	cin >> N >> B;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			A[i].push_back(num);
		}
	}

	ans = conquer(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] % 1000 << " ";
		}
		cout << endl;
	}
}