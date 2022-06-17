#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		priority_queue<int> maxpq;		//�ִ� ����
		priority_queue<int, vector<int>, greater<int>> minpq;	//�ּڰ� ����
		unordered_map<int, int> m;		//���� �����ִ� ���� ����

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
						while (m[minpq.top()] == 0) {	//���� ���ڰ� �����ִٸ�
							minpq.pop();				//��� pop
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
						while (m[maxpq.top()] == 0) {	//���� ���ڰ� �����ִٸ�
							maxpq.pop();				//��� pop
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

		while (!maxpq.empty()) {		//���� ���� pop
			if (m[maxpq.top()] == 0) {
				maxpq.pop();
			}
			else {
				break;
			}
		}

		while (!minpq.empty()) {		//���� ���� pop
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