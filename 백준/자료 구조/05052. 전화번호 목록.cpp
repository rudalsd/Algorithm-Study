#include<iostream>

using namespace std;

int n, t;

struct trie {
	trie* num[10];
	bool end;

	trie() {
		end = false;
		for (int i = 0; i < 10; i++) num[i] = NULL;
	}
	~trie() {
		for (int i = 0; i < 10; i++) {
			if (num[i]) delete num[i];
		}
	}

	void insert(const char* ch) {
		if (!*ch) {
			this->end = true;
			return;
		}

		int now = *ch - '0';
		if (!num[now]) num[now] = new trie;
		num[now]->insert(ch + 1);
	}

	bool find(const char* ch) {
		if (!*ch || end) {
			return true;
		}

		int now = *ch - '0';
		if (!num[now]) return false;
		return num[now]->find(ch + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		trie* root = new trie;
		bool flag = true;

		cin >> n;

		for (int i = 0; i < n; i++) {
			char arr[11];
			cin >> arr;

			if (root->find(arr)) {
				if (flag) cout << "NO\n";
				flag = false;
			}
			else {
				root->insert(arr);
			}
		}

		if (flag) {
			cout << "YES\n";
		}

		delete root;
	}
}