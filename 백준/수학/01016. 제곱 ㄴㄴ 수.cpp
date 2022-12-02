#include<iostream>
#define ll long long

using namespace std;

ll arr[1000001];
ll Min, Max;
int ans;

int main()
{
	scanf("%lld %lld", &Min, &Max);
	ans = Max - Min + 1;	//범위 내 모든 수의 개수

	for (ll i = 2; i * i <= Max; i++) {
		ll pow = i * i;		//제곱수
		ll cnt = Min / pow;	//범위 내 나누어 떨어지는 수의 최솟값

		if (Min % pow) cnt++;	//나누어 떨어지지 않으면 몫 + 1

		for (ll j = cnt; j * pow <= Max; j++) {
			if (arr[j * pow - Min] != 1) {
				arr[j * pow - Min] = 1;
				ans--;
			}
		}
	}

	printf("%lld", ans);
}