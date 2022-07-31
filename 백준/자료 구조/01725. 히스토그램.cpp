#include<iostream>
#include<stack>

using namespace std;

int N;
int arr[100005];
int ans;

int main()
{
	stack<int> s;
	s.push(0);
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N + 1; i++) {
		while (!s.empty() && arr[i] < arr[s.top()]) {
			int cur = s.top();
			s.pop();
			int W = arr[cur] * (i - s.top() - 1);
			ans = max(ans, W);
		}
		s.push(i);
	}

	printf("%d", ans);
}