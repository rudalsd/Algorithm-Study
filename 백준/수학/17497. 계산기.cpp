#include<iostream>
#include<vector>
#define ll long long

using namespace std;

ll N;
vector<char> ans;

int main()
{
	scanf("%lld", &N);

	while (N) {
		if (N & 1) {	//무조건 2로 나눈 경우
			ans.push_back('/');
			N *= 2;
		}
		else if (N & 2) {	//무조건 2를 더한 경우
			ans.push_back('+');
			N -= 2;
		}
		else {	//무조건 2를 곱한 경우
			ans.push_back('*');
			N /= 2;
		}
	}

	if (ans.size() > 99) {
		printf("-1");
	}
	else {
		printf("%d\n", ans.size());
		for (int i = ans.size() - 1; i >= 0; i--) {
			printf("[%c] ", ans[i]);
		}
	}
}