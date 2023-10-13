#include<iostream>
#include<algorithm>

using namespace std;

int arr[2000];
int dif[2000];
int T, N;
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
  
	cin >> T;
  
	while (T--) {
		cin >> N;
    
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
    
		sort(arr, arr + N);
    
		for (int i = 0; i < N - 1; i++) {
			dif[i] = arr[i + 1] - arr[i];
		}
    
		ans = dif[0];
    
		for (int i = 1; i < N - 1; i++) {
			ans = euclid(ans, dif[i]);
		}
    
		if (ans == 0) {
			cout << "INFINITY\n";
		}
		else {
			cout << ans << '\n';
		}
	}
}
