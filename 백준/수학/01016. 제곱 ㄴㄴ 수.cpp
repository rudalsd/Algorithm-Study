#include<iostream>
#define ll long long

using namespace std;

ll arr[1000001];
ll Min, Max;
int ans;

int main()
{
	scanf("%lld %lld", &Min, &Max);
	ans = Max - Min + 1;	//���� �� ��� ���� ����

	for (ll i = 2; i * i <= Max; i++) {
		ll pow = i * i;		//������
		ll cnt = Min / pow;	//���� �� ������ �������� ���� �ּڰ�

		if (Min % pow) cnt++;	//������ �������� ������ �� + 1

		for (ll j = cnt; j * pow <= Max; j++) {
			if (arr[j * pow - Min] != 1) {
				arr[j * pow - Min] = 1;
				ans--;
			}
		}
	}

	printf("%lld", ans);
}