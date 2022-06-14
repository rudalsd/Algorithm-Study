#include<iostream>
#include<string>
#include<stack>

using namespace std;

string str, bomb;

int main()
{
	cin >> str >> bomb;

	stack<char> ans;
	stack<char> temp;

	for (int i = 0; i < str.size(); i++) {
		ans.push(str[i]);				//stack의 크기가 폭탄문자열의 길이보다 길고 문자가 일치한다면
		if (ans.size() >= bomb.size() && ans.top() == bomb[bomb.size() - 1]) {
			for (int j = bomb.size() - 1; j >= 0; j--) {
				if (bomb[j] == ans.top()) {		//임시로 temp스택에 저장
					temp.push(ans.top());
					ans.pop();
				}
			}
			if (temp.size() == bomb.size()) {	//폭탄 문자열이 나오면
				while (!temp.empty()) {			//temp스택을 비움
					temp.pop();
				}
			}
			else {
				while (!temp.empty()) {			//ans 스택에 temp를 다시 넣어줌
					ans.push(temp.top());
					temp.pop();
				}
			}
		}
	}

	while (!ans.empty()) {		//스택을 그대로 출력하면 반대로 나오므로
		temp.push(ans.top());	//temp 스택에 다시 넣어줌
		ans.pop();
	}

	if (temp.size() == 0) {
		cout << "FRULA";
	}
	else {
		while (!temp.empty()) {
			printf("%c", temp.top());
			temp.pop();
		}
	}
}