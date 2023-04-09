#include<iostream>
#include<vector>

using namespace std;

int A, B;
vector<pair<int, int>> ans;
int idx;

int Euclid(int B, int A) {
	while (B != 0) {
		int temp = A % B;
		A = B;
		B = temp;
	}

	return A;
}

int main()
{
	scanf("%d %d", &A, &B);

	int temp = B / A;

	for (int i = 1; i*i <= temp; i++) {
		if (temp % i == 0) {
			if (Euclid(i, temp / i) == 1) {
				ans.push_back({ i * A, temp / i * A });
			}
		}
	}

	int min = 987654321;

	for (int i = 0; i < ans.size();i++) {
		if (min > ans[i].first + ans[i].second) {
			min = ans[i].first + ans[i].second;
			idx = i;
		}
	}

	printf("%d %d", ans[idx].first, ans[idx].second);
}