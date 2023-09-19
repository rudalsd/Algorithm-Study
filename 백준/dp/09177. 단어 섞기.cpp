#include<iostream>
#include<string>

using namespace std;

int N;
int dp[201][201];
string a, b, c;

int dfs(int i, int j)
{
	if (i + j == c.size() - 1) return 1;
 	if (dp[i][j] != -1) return dp[i][j];
	int& ret = dp[i][j];
	ret = 0;

	if (a[i + 1] == c[i + j + 1]) {
		ret = max(ret, dfs(i + 1, j));
	}
	
	if (b[j + 1] == c[i + j + 1]) {
		ret = max(ret, dfs(i, j + 1));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for(int t = 1;t<=N;t++){
		cin >> a >> b >> c;

		a = ' ' + a;
		b = ' ' + b;
		c = ' ' + c;

		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				dp[i][j] = -1;
			}
		}

		cout << "Data set " << t << ": ";

		if (dfs(0, 0)) {
			cout << "yes";
		}
		else {
			cout << "no";
		}

		cout<<'\n';
	}
}
