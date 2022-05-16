#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	cin >> input;
	int N;
	cin >> N;
	int dp[300] = { 0 };
	vector<string> box;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		box.push_back(str);
	}

	dp[input.size()] = 1;

	for (int i = input.size() - 1; i >= 0; i--) {
		for (int j = 0; j < box.size(); j++) {
			if (input.find(box[j], i) != -1 && input.find(box[j], i) == i) {
				if (dp[i + box[j].size()] == 1) {
					dp[i] = 1;
					break;
				}
				else dp[i] = 0;
			}
		}
	}

	cout << dp[0];
}