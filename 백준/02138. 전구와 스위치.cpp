#include <iostream>
#include <string>

using namespace std;

string bulb;
string result;
int N;

int main()
{
	cin >> N;
	cin >> bulb;
	cin >> result;
	string bulb2;
	bulb = bulb + '-';
	bulb2 = bulb;
	result = result + '-';
	int m = 100000;
	int cnt = 0;

	for (int i = 1; i < N; i++)
	{
		if (bulb[i - 1] != result[i - 1])
		{
			cnt++;
			for (int j = -1; j < 2; j++) {
				if (bulb[i + j] == '1')
					bulb[i + j] = '0';
				else if (bulb[i + j] == '0')
					bulb[i + j] = '1';
			}
		}
	}

	if (bulb == result)
		cout << cnt;
	else {
		cnt = 1;
		for (int i = 0; i < 2; i++)
		{
			if (bulb2[i] == '1')
				bulb2[i] = '0';
			else if (bulb2[i] == '0')
				bulb2[i] = '1';
		}

		for (int i = 1; i < N; i++)
		{
			if (bulb2[i - 1] != result[i - 1])
			{
				cnt++;
				for (int j = -1; j < 2; j++) {
					if (bulb2[i + j] == '1')
						bulb2[i + j] = '0';
					else if (bulb2[i + j] == '0')
						bulb2[i + j] = '1';
				}
			}
		}

		if (bulb2 == result)
			cout << cnt;
		else
			cout << -1;
	}
}
