#include<iostream>

using namespace std;

int N;
int Max[3];
int Min[3];
int tempMax[3];
int tempMin[3];
int dx[3] = { -1,0,1 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		tempMax[0] = max(Max[0], Max[1]) + a;
		tempMax[1] = max(Max[0], max(Max[1], Max[2])) + b;
		tempMax[2] = max(Max[1], Max[2]) + c;
		tempMin[0] = min(Min[0], Min[1]) + a;
		tempMin[1] = min(Min[0], min(Min[1], Min[2])) + b;
		tempMin[2] = min(Min[1], Min[2]) + c;
		for (int j = 0; j < 3; j++) {
			Max[j] = tempMax[j];
			Min[j] = tempMin[j];
		}
	}

	cout << max(Max[0], max(Max[1], Max[2])) << " " << min(Min[0], min(Min[1], Min[2]));
}