#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[1000001];
vector<int> dp;

int binarySearch(int num)								//이분탐색으로 주어진 num이 처음으로 dp 내에서 다른 수보다 커진 위치를 찾는다.
{
	int start, end, middle;
	start = 0;
	end = dp.size() - 1;
	middle = 0;

	while (start < end)
	{
		middle = (start + end) / 2;
		if (dp[middle] > num) {
			end = middle;
		}
		else if (dp[middle] < num) {
			start = middle + 1;
		}
		else {
			return middle;
		}
	}

	return end;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	dp.push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		if (dp[dp.size() - 1] < arr[i]) {				//dp의 마지막 수보다 더 크면 pushback
			dp.push_back(arr[i]);
		}
		else {
			int index = binarySearch(arr[i]);			//아니라면 이분 탐색
			dp[index] = arr[i];
		}
	}

	cout << dp.size();									//dp의 사이즈가 답
}