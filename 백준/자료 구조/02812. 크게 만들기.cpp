#include<iostream>
#include<stack>

using namespace std;

int N, K;
char arr[500001];

int main()
{
	scanf("%d %d", &N, &K);

	scanf("%s", arr);

	stack<int> s;
	stack<int> ans;
	s.push(arr[0] - '0');

	int cnt = 0;

	for (int i = 1; i < N; i++) {
		while (!s.empty()) {
			if (s.top() < arr[i] - '0' && cnt < K) {
				s.pop();
				cnt++;
			}
			else break;
		}
		s.push(arr[i] - '0');
	}

	while (!s.empty()) {
		ans.push(s.top());
		s.pop();
	}

	for (int i = 0; i < N - K; i++) {
		printf("%d", ans.top());
		ans.pop();
	}
}