#include <iostream>

using namespace std;

int arr[55];

int main()
{
	int N, M;
	int box = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cnt += arr[i];
		if (cnt > M) {
			box++;
			cnt = arr[i];
		}
		else if (cnt == M) {
			box++;
			cnt = 0;
		}
	}
	if (cnt != 0)
		box++;


	cout << box;
}