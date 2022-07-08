#include<iostream>
#include<stack>

using namespace std;

int N;

struct node {
	int num;	//키
	int cnt;	//붙어있는 같은 키를 가진 사람
};

int main()
{
	cin >> N;

	stack<node> s;

	long long ans = 0;

	for (int i = 0; i < N; i++) {
		int cur;
		scanf("%d", &cur);
		int cnt = 1;

		while (!s.empty() && s.top().num < cur) {	//바로 앞사람의 키보다 현재 키가 더 클 때
			ans += s.top().cnt;
			s.pop();
		}
		if (!s.empty()) {	//stack이 비어있지 않을 때
			if (s.top().num == cur) {	//앞사람과 현재의 키가 같을 때
				ans += s.top().cnt;		//앞에 같은 키를 가진 사람 수만큼 ans에 더해줌
				cnt = s.top().cnt + 1;	//현재를 포함해서 같은 키를 가진 사람 + 1
				if (s.size() > 1) {		//같은 키를 가진 사람들 보다 큰 사람이 존재하면
					ans++;
				}
				s.pop();
			}
			else {	//앞사람이 현재의 키보다 클 때
				ans++;
			}
		}

		s.push({ cur, cnt });
	}

	cout << ans;
}