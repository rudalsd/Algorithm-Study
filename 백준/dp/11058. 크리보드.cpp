#include<iostream>
#define ll long long

using namespace std;

ll arr[101];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N <= 6) {
		cout << N;
		return 0;
	}

	for (int i = 1; i <= 6; i++) {
		arr[i] = i;
	}

	for (int i = 7; i <= N; i++) {
		arr[i] = max(arr[i - 4] * 3, arr[i - 5] * 4);
		arr[i] = max(arr[i], arr[i - 3] * 2);
	}

	cout << arr[N];
}
