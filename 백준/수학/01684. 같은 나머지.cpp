#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[1000];
int dif[1000];
int ans;

int euclid(int a, int b)
{
	while (b) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {
		dif[i] = arr[i + 1] - arr[i];
	}

	ans = dif[0];

	for (int i = 1; i < n - 1; i++) {
		ans = euclid(ans, dif[i]);
	}

	cout << ans;
}
