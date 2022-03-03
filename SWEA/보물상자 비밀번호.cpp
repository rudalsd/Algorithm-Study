#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, K;

string rotate(string num)
{
	char tmp = num[num.size() - 1];
	for (int i = num.size() - 1; i > 0; i--) {
		num[i] = num[i - 1];
	}
	num[0] = tmp;

	return num;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		unordered_map<string, int> map;
		string num;
		vector<string> v;
		cin >> N >> K;
		cin >> num;
		for (int i = 0; i < N / 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (map.count(num.substr(j * N / 4, N / 4)) == 0) {
					map[num.substr(j * N / 4, N / 4)]++;
					v.push_back(num.substr(j * N / 4, N / 4));
				}
			}
			num = rotate(num);
		}

		sort(v.begin(), v.end(), greater<>());
		int result = 0;
		int len = v[K - 1].size();
		for (int i = 0; i < len; i++)
		{
			if (v[K - 1][i] >= '0' && v[K - 1][i] <= '9')
			{
				result += ((int)v[K - 1][i] - '0') * pow(16, len - 1 - i);
			}
			else {
				result += ((int)v[K - 1][i] - 'A' + 10) * pow(16, len - 1 - i);
			}
		}

		cout << "#" << t << " " << result << endl;
	}
}