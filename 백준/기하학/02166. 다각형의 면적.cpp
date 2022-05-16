#include<iostream>
#include<math.h>

using namespace std;

double x[10001];
double y[10001];

int main()
{
	int N;
	cin >> N;
	double result = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	result = x[N - 1] * y[0] - y[N - 1] * x[0];

	for (int i = 0; i < N - 1; i++) {
		result += (x[i] * y[i + 1]);
		result -= (y[i] * x[i + 1]);
	}

	printf("%.1lf", abs(result) / 2.0);
}