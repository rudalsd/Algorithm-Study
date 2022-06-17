#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		priority_queue<int> maxpq;		//최댓값 저장
		priority_queue<int, vector<int>, greater<int>> minpq;	//최솟값 저장
		unordered_map<int, int> m;		//현재 남아있는 숫자 저장

		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char ch;
			cin >> ch;
			if (ch == 'I') {
				int num;
				cin >> num;
				maxpq.push(num);
				minpq.push(num);
				m[num]++;
			}
			else {
				int num;
				cin >> num;
				if (num == -1) {
					if (!minpq.empty()) {
						while (m[minpq.top()] == 0) {	//없는 숫자가 남아있다면
							minpq.pop();				//모두 pop
							if (minpq.empty()) {
								break;
							}
						}
						if (!minpq.empty()) {
							m[minpq.top()]--;
							minpq.pop();
						}
					}
				}
				else {
					if (!maxpq.empty()) {
						while (m[maxpq.top()] == 0) {	//없는 숫자가 남아있다면
							maxpq.pop();				//모두 pop
							if (maxpq.empty()) {
								break;
							}
						}
						if (!maxpq.empty()) {
							m[maxpq.top()]--;
							maxpq.pop();
						}
					}
				}
			}
		}

		while (!maxpq.empty()) {		//없는 숫자 pop
			if (m[maxpq.top()] == 0) {
				maxpq.pop();
			}
			else {
				break;
			}
		}

		while (!minpq.empty()) {		//없는 숫자 pop
			if (m[minpq.top()] == 0) {
				minpq.pop();
			}
			else {
				break;
			}
		}

		if (maxpq.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << maxpq.top() << " " << minpq.top() << endl;
		}
	}
}