#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[1000001];
vector<int> dp;

int binarySearch(int num)								//�̺�Ž������ �־��� num�� ó������ dp ������ �ٸ� ������ Ŀ�� ��ġ�� ã�´�.
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
		if (dp[dp.size() - 1] < arr[i]) {				//dp�� ������ ������ �� ũ�� pushback
			dp.push_back(arr[i]);
		}
		else {
			int index = binarySearch(arr[i]);			//�ƴ϶�� �̺� Ž��
			dp[index] = arr[i];
		}
	}

	cout << dp.size();									//dp�� ����� ��
}