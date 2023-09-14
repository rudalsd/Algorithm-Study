#include<iostream>
#include<unordered_map>
#define ll long long

using namespace std;

int N, K;
int arr[200001];
unordered_map<int, ll> um;
ll ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	um[0] = 1;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];

		ans += um[arr[i] - K];

		um[arr[i]]++;
	}

	cout << ans;
}