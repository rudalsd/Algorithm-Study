#include<iostream>

using namespace std;

int N;

struct Trie {
	Trie* arr[26];
	int end;

	Trie() {
		for (int i = 0; i < 26; i++) {
			arr[i] = NULL;
		}

		end = 0;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (arr[i]) delete arr[i];
		}
	}

	void insert(const char* ch) {
		char temp = *ch - 'a';
		if (!*ch) {
			end++;
			return;
		}

		if (arr[temp] == NULL) arr[temp] = new Trie;
		arr[temp]->insert(ch + 1);
	}

	void print(const char* ch) {
		char temp = *ch - 'a';
		if (!*ch) {
			if (end) {
				cout << end + 1;
			}
			cout << '\n';
			return;
		}

		cout << *ch;

		if (arr[temp] == NULL) {
			cout << '\n';
			return;
		}

		arr[temp]->print(ch + 1);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Trie* root = new Trie;

	for (int i = 0; i < N; i++) {
		char ch[11];
		cin >> ch;

		root->print(ch);
		root->insert(ch);
	}
}