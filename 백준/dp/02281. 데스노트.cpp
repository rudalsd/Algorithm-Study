#include<iostream>
#include<cstring>

using namespace std;

int n, m;
int name[1001];
int dp[1001][1001];	//i번 이름, 해당 줄에 지금까지 쓰인 글자 수


int go(int idx, int len)	//len = 가장 뒤의 공백 포함
{
	if (idx > n) return 0;

	int& ret = dp[idx][len];
	if (ret != -1) return ret;

	//다음 줄에 쓰는 경우
	ret = (m - len + 1) * (m - len + 1) + go(idx + 1, name[idx] + 1);

	//현재 줄에 쓰는 경우
	if (len + name[idx] <= m) {
		ret = min(ret, go(idx + 1, len + name[idx] + 1));
	}

	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &name[i]);
	}

	memset(dp, -1, sizeof(dp));

	printf("%d", go(1, 0));
}