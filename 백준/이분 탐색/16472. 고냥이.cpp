#include<iostream>
#include<string>

using namespace std;

int N;
string str;
int cnt[26];
int ch;
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> str;

	int s = 0;
	int e = 0;

	cnt[str[0] - 'a']++;
	ch++;
	ans = 1;

	while (e < str.size()) {
		if (ch <= N) {
			ans = max(ans, e - s + 1);
			e++;
			if (cnt[str[e] - 'a'] == 0) ch++;
			cnt[str[e] - 'a']++;
		}
		else {
			cnt[str[s] - 'a']--;
			if (cnt[str[s] - 'a'] == 0) ch--;
			s++;
		}
	}

	cout << ans;
}
