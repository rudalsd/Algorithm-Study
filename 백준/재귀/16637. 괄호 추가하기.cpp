#include<iostream>

using namespace std;

int N;
char arr[20];	//식
int visited[20];	//괄호 여부
int ans = -987654321;

void dfs(int level, int limit, int num)
{
	if (level == limit) {
		int ret = arr[0] - '0';
		int before;
		for (int i = 1; i < N; i += 2) {
			if (visited[i] == -1) {	//괄호 안에 있는 연산자라면
				int temp;
				if (arr[i] == '+') {
					temp = (arr[i - 1] - '0') + (arr[i + 1] - '0');
				}
				else if (arr[i] == '-') {
					temp = (arr[i - 1] - '0') - (arr[i + 1] - '0');
				}
				else if (arr[i] == '*') {
					temp = (arr[i - 1] - '0') * (arr[i + 1] - '0');
				}

				if (i != 1) {
					if (arr[i - 2] == '+') {
						ret = ret - (arr[i - 1] - '0') + temp;
					}
					else if (arr[i - 2] == '-') {
						ret = ret + (arr[i - 1] - '0') - temp;
					}
					else if (arr[i - 2] == '*') {
						if (arr[i - 1] - '0' == 0) {
							ret = before * temp;
						}
						else {
							ret = ret / (arr[i - 1] - '0') * temp;
						}
					}
				}
				else {
					ret = temp;
				}
			}
			else {	//괄호 밖의 연산자라면
				if (arr[i] == '+') {
					ret += arr[i + 1] - '0';
				}
				else if (arr[i] == '-') {
					ret -= arr[i + 1] - '0';
				}
				else if (arr[i] == '*') {
					if (arr[i + 1] - '0' == 0) {
						before = ret;
						ret = 0;
					}
					else {
						ret *= arr[i + 1] - '0';
					}
				}
			}
		}
		ans = max(ans, ret);
		return;
	}

	for (int i = num; i < N; i++) {
		if (i % 2 == 1) {
			if (visited[i] == 0) {
				visited[i] = -1;
				visited[i + 2] = 1;
				dfs(level + 1, limit, i + 4);
				visited[i] = 0;
				visited[i + 2] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	scanf("%s", arr);

	for (int i = 0; i <= (N + 1) / 4; i++) {	//괄호의 개수
		dfs(0, i, 1);
	}

	printf("%d", ans);
}