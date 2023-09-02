#include<iostream>
#include<queue>

using namespace std;

int visited[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cmd;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> greater;
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> less;

	while (1) {
		cin >> cmd;

		if (cmd == 1) {
			int K, P;
			cin >> K >> P;
			greater.push({ P,K });
			less.push({ P,K });
			visited[K] = 0;
		}
		else if (cmd == 2) {
			while (1) {
				if (less.empty()) {
					cout << 0 << '\n';
					break;
				}
				const int K = less.top().second;
				less.pop();
				if (visited[K] != 1) {
					visited[K] = 1;
					cout << K << '\n';
					break;
				}
			}
		}
		else if (cmd == 3) {
			while (1) {
				if (greater.empty()) {
					cout << 0 << '\n';
					break;
				}
				const int K = greater.top().second;
				greater.pop();
				if (visited[K] != 1) {
					visited[K] = 1;
					cout << K << '\n';
					break;
				}
			}
		}
		else {
			return 0;
		}
	}
}