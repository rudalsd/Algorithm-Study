#include <iostream>

using namespace std;

int main()
{
	int brown, yellow;
	cin >> brown >> yellow;

	brown = (brown - 4) / 2;

	for (int i = 1; i <= brown / 2; i++) {
		if (i * (brown - i) == yellow) {
			yellow = i;
			brown = brown - i;
			break;
		}
	}

	cout << brown + 2 << " " << yellow + 2;
}