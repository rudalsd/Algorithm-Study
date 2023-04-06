#include<iostream>
#define ll long long

using namespace std;

int N;
int arr[100000];
int check[100001];
int s, e;
ll ans;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	check[arr[s]] = 1;

	while (s <= e && e < N) {

		if (check[arr[e]] <= 1) {
			ans += e - s + 1;
		}

		if (check[arr[e]] > 1) {
			check[arr[s]]--;
			s++;
		}
		else {
			e++;
			check[arr[e]]++;
		}

	}

	printf("%lld", ans);
}