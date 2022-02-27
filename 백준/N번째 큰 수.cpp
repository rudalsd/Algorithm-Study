#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;

	arr.resize(num * num);

	for (int i = 0; i < num * num; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cout << arr[arr.size() - num];
}