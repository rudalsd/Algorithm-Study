#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int N;

struct Trie {
	map<string, Trie*> m;

	void insert(vector<string> vect, int level) {
		if ((int)vect.size() > level) {
			if (!m.count(vect[level])) {
				m[vect[level]] = new Trie;
			}

			m[vect[level]]->insert(vect, level + 1);
		}
	}

	void print(int level) {
		if (m.empty()) return;
		for (auto& next : m) {
			for (int i = 0; i < level; i++) {
				cout << ' ';
			}
			cout << next.first << '\n';
			next.second->print(level + 1);
		}
	}
};

vector <string> split(string str) {
	vector <string> ret;

	int s = 0;
	int e = 0;

	while (1) {
		e = str.find('\\', s);
		if (e == -1) {
			ret.push_back(str.substr(s, str.size() - s));
			break;
		}
		else {
			ret.push_back(str.substr(s, e - s));
			s = e + 1;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Trie* root = new Trie;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		vector<string> vect = split(str);

		root->insert(vect, 0);
	}

	root->print(0);
}