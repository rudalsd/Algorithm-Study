#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#define ll long long

using namespace std;

int N;
pair<ll,int> arr[26];
bool isFirst[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 26; i++) {
		arr[i].second = i;
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		isFirst[str[0] - 'A'] = true;

		for (int j = 0; j < str.size(); j++) {
			arr[str[j] - 'A'].first += pow(10, str.size() - j - 1);
		}
	}

	sort(arr, arr + 26, greater<>());

	if (isFirst[arr[9].second]) {
		for (int i = 8; i >= 0; i--) {
			if (isFirst[arr[i].second] == false) {
				swap(arr[9], arr[i]);
				break;
			}
		}
	}

	sort(arr, arr + 9, greater<>());

	ll ans = 0;
	int cnt = 9;

	for (int i = 0; i < 10; i++) {
		ans += arr[i].first * cnt--;
	}

	cout << ans;
}