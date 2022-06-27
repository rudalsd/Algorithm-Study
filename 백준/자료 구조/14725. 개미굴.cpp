#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int N;

struct Trie {
	map<string, Trie*> m;		//������������ ����ϱ� ���ؼ� map�� ��
	~Trie() {					//�Ҹ��ڷ� ���� �Ҵ��� Trie���� delete
		for (auto it = m.begin(); it != m.end(); it++) {
			delete it->second;
		}
	}

	void Insert(vector<string> vect, int idx)
	{
		if (vect.size() == idx) return;	//��� �����ߴٸ� return

		if (m.find(vect[idx]) == m.end()) {	//vect[idx]�� map�� ���ٸ�
			m.insert({ vect[idx], new Trie });
		}

		m[vect[idx]]->Insert(vect, idx + 1);	//���� �ܾ ����
	}

	void Find(int depth)
	{
		for (auto it = m.begin(); it != m.end(); it++) {
			for (int i = 0; i < depth; i++) {
				printf("--");
			}
			cout << it->first << '\n';

			it->second->Find(depth + 1);
		}
	}
};

int main()
{
	Trie* root = new Trie();
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		vector<string> vect(n);
		for (int j = 0; j < n; j++) {
			cin >> vect[j];
		}

		root->Insert(vect, 0);
	}

	root->Find(0);
	delete root;
}