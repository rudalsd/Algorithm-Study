#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int N;
int box[26];
int ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++) {
			box[str[j] - 'A'] += pow(10, str.size() - j - 1);
		}
	}

	sort(box, box + 26, greater<>());

	int seq = 0;

	for (int i = 9; i >= 0; i--) {
		ans += box[seq] * i;
		seq++;
	}

	cout << ans;
}
