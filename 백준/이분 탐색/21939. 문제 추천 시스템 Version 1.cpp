#include<iostream>
#include<set>
#include<string>

using namespace std;

int N, M;
int level[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	set<pair<int,int>> s;

	for (int i = 0; i < N; i++) {
		int P, L;
		cin >> P >> L;

		level[P] = L;
		s.insert({ L,P });
	}
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			int P, L;
			cin >> P >> L;

			level[P] = L;
			s.insert({ L,P });
		}
		else if (cmd == "recommend") {
			int x;
			cin >> x;

			if (x == 1) {
				cout << (*s.rbegin()).second << '\n';
			}
			else {
				cout << (*s.begin()).second << '\n';
			}
		}
		else {
			int P;
			cin >> P;

			s.erase({ level[P],P });
		}
	}
}
