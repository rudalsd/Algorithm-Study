#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

string S, T;
unordered_map<string, int> visited;

string change(string S)
{
	string temp;

	for (int i = S.size()-1; i >= 0; i--) {
		temp += S[i];
	}

	return temp;
}

int main()
{
	cin >> S >> T;

	queue<string> q;

	q.push(T);
	visited[T] = 1;

	while (!q.empty()) {
		string A = q.front();
		q.pop();

		if (A == S) {
			printf("1");
			return 0;
		}
		if (A.size() == S.size()) continue;

		string temp = A;
		if (temp[temp.size() - 1] == 'A') {
			temp.erase(temp.end() - 1);
			if (visited[temp] != 1) {
				visited[temp] = 1;
				q.push(temp);
			}
		}

		temp = A;

		if (temp[0] == 'B') {
			temp = change(temp);
			temp.erase(temp.end() - 1);
			if (visited[temp] != 1) {
				visited[temp] = 1;
				q.push(temp);
			}
		}
	}

	printf("0");
}
