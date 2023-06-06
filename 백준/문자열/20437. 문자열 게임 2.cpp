#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string W;
		int K;
		int cnt[200] = { 0 };
		vector<int> list[200];
		int Min = 987654321;
		int Max = 0;
		cin >> W >> K;

		for (int i = 0; i < W.size(); i++) {
			cnt[W[i]]++;
			list[W[i]].push_back(i);
		}

		for (int i = 'a'; i <= 'z'; i++) {
			if (cnt[i] >= K) {
				for (int j = 0; j < cnt[i] - K + 1; j++) {
					Min = min(Min, list[i][j + K - 1] - list[i][j] + 1);
					Max = max(Max, list[i][j + K - 1] - list[i][j] + 1);
				}
			}
		}
		if (Min == 987654321 || Max == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << Min << ' ' << Max << '\n';
		}
	}
}