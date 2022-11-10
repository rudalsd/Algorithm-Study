#include<iostream>

using namespace std;

pair<int, int> P[3];
pair<int, int> vect[2];

int main()
{
	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		P[i] = { x,y };
	}

	vect[0] = { P[0].first - P[1].first, P[0].second - P[1].second };
	vect[1] = { P[0].first - P[2].first, P[0].second - P[2].second };

	int ans = vect[0].first * vect[1].second - vect[0].second * vect[1].first;

	if (ans > 0) {	//반시계
		printf("%d", 1);
	}
	else if (ans < 0) {	//시계
		printf("%d", -1);
	}
	else {	//일직선
		printf("%d", 0);
	}
}