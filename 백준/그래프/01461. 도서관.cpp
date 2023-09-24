#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> L, R;
int ans;
int Max;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n < 0) {
			L.push_back(n);
		}
		else {
			R.push_back(n);
		}
	}

	sort(R.begin(), R.end());
	sort(L.begin(), L.end(), greater<>());

	for (int i = R.size() - 1; i >= 0; i -= M) {
		ans += R[i] * 2;
	}

	for (int i = L.size() - 1; i >= 0; i -= M) {
		ans += -L[i] * 2;
	}

	if (!R.empty()) Max = max(Max, *R.rbegin());
	if (!L.empty()) Max = max(Max, -(*L.rbegin()));

	cout << ans - Max;
}