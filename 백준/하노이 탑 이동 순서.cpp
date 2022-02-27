#include<iostream>

using namespace std;

int pow(int x, int n)
{
	int a = 1;

	if (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			a *= x;
		}
	}
	return a;
}

void hanoi(int start, int mid, int end, int n)
{
	if (n == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}

	hanoi(start, end, mid, n - 1);
	hanoi(start, mid, end, 1);
	hanoi(mid, start, end, n - 1);
}

int main()
{
	int n;
	cin >> n;

	int count = pow(2, n) - 1;

	cout << count << endl;

	hanoi(1, 2, 3, n);
}