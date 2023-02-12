#include<iostream>
#include<stack>

using namespace std;

int N;

int main()
{
	stack<pair<int,int>> s;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int h;
		scanf("%d", &h);

		while (!s.empty()) {
			if (s.top().second > h) {
				printf("%d ", s.top().first);
				break;
			}
			s.pop();
		}

		if (s.empty()) {
			printf("0 ");
		}

		s.push({ i,h });
	}
}