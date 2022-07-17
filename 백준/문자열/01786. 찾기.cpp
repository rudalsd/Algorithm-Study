#include<iostream>
#include<string>
#include<vector>

using namespace std;

string T, P;
vector<int> Pi;
vector<int> ans;

void findK(string P)		//찾을 문자열 P 전처리
{
	Pi.resize(P.size());

	int cur = 0;

	for (int i = 1; i < P.size(); i++) {
		while (P[i] != P[cur] && cur > 0) {
			cur = Pi[cur - 1];
		}
		if (P[i] == P[cur]) {
			Pi[i] = cur + 1;
			cur++;
		}
	}
}

void KMP(string T, string P)	//T에서 P찾기
{
	int cur = 0;
	for (int i = 0; i < T.size(); i++) {
		while (cur > 0 && T[i] != P[cur]) {
			cur = Pi[cur - 1];
		}
		if (T[i] == P[cur]) {
			if (cur == P.size() - 1) {
				ans.push_back(i - cur + 1);
				cur = Pi[cur];
			}
			else {
				cur++;
			}
		}
	}
}

int main()
{
	getline(cin, T);
	getline(cin, P);

	findK(P);

	KMP(T, P);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}