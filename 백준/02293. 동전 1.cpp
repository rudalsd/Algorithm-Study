#include<iostream>

using namespace std;

int arr[110010];						//경우의 수 저장할 배열
int coin[110];							//동전의 가격 저장 배열

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	arr[0] = 1;

	for (int i = 0; i < n; i++) {					//중복을 제외하기 위해서 n개의 코인을 k번씩 돌리기
		for (int j = 0; j < k; j++) {
			arr[j + coin[i]] += arr[j];				//j + coin[i]번째 배열의 값에 j번째 값을 더하기(경우의 수 합산)
		}
	}

	printf("%d", arr[k]);
}