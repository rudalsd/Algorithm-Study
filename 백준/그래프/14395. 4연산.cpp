#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#define ll long long

using namespace std;

int main()
{
	ll s, t;
	unordered_map<ll, int> m;

	scanf("%lld %lld", &s, &t);

	if (s == t) {
		printf("0");
		return 0;
	}

	queue<pair<ll, string>> q;

	string str;

	q.push({ s,str });

	while (!q.empty()) {
		const ll cur = q.front().first;
		const string str = q.front().second;
		q.pop();

		if (m[cur] != 0) continue;
		m[cur] = 1;

		if (cur == t) {
			cout << str;
			return 0;
		}

		if (cur * cur <= t) {
			if (m[cur * cur] != 1) {
				q.push({ cur * cur,str + '*' });
			}
		}

		if (cur * 2 <= t) {
			if (m[cur * 2] != 1) {
				q.push({ cur * 2,str + '+' });
			}
		}

		if (m[0] != 1) {
			q.push({ 0, str + '-' });
		}

		if (cur != 0) {
			if (m[1] != 1) {
				q.push({ 1,str + '/' });
			}
		}
	}

	printf("-1");
}