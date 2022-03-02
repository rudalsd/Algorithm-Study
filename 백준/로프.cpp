#include <iostream>
#include <algorithm>

using namespace std;

int rope[100000];

int main()
{
	int N;
	int max = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope, rope + N);

	for (int i = 0; i < N; i++) {
		if (rope[i] * (N - i) > max)
			max = rope[i] * (N - i);
	}

	cout << max;
}