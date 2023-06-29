#include<iostream>
#include<deque>
#include<string>

using namespace std;

int T;
deque<int> deq;

void preproc(string x)
{
	int num = 0;
	for (auto next : x) {
		if (next >= '0' && next <= '9') {
			num *= 10;
			num += next - '0';
		}
		else if (next == ']' || next == ',') {
			deq.push_back(num);
			num = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		bool flag = true;
		bool rev = false;
		deq.clear();
		string p, x;
		int n;
		cin >> p >> n >> x;

		if (n) preproc(x);

		for (auto com : p) {
			if (com == 'R') {
				rev = !rev;
			}
			else {
				if (!deq.empty()) {
					if (rev) {
						deq.pop_back();
					}
					else {
						deq.pop_front();
					}
				}
				else {
					cout << "error\n";
					flag = false;
					break;
				}
			}
			
		}

		if (flag) {
			cout << '[';
			while (!deq.empty()) {
				if (rev) {
					if (deq.size() == 1) {
						cout << deq.back();
					}
					else {
						cout << deq.back() << ',';
					}
					deq.pop_back();
				}
				else {
					if (deq.size() == 1) {
						cout << deq.front();
					}
					else {
						cout << deq.front() << ',';
					}
					deq.pop_front();
				}
			}
			cout << "]\n";
		}
	}
}
