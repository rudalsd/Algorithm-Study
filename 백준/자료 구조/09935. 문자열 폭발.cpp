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
		ans.push(str[i]);				//stack�� ũ�Ⱑ ��ź���ڿ��� ���̺��� ��� ���ڰ� ��ġ�Ѵٸ�
		if (ans.size() >= bomb.size() && ans.top() == bomb[bomb.size() - 1]) {
			for (int j = bomb.size() - 1; j >= 0; j--) {
				if (bomb[j] == ans.top()) {		//�ӽ÷� temp���ÿ� ����
					temp.push(ans.top());
					ans.pop();
				}
			}
			if (temp.size() == bomb.size()) {	//��ź ���ڿ��� ������
				while (!temp.empty()) {			//temp������ ���
					temp.pop();
				}
			}
			else {
				while (!temp.empty()) {			//ans ���ÿ� temp�� �ٽ� �־���
					ans.push(temp.top());
					temp.pop();
				}
			}
		}
	}

	while (!ans.empty()) {		//������ �״�� ����ϸ� �ݴ�� �����Ƿ�
		temp.push(ans.top());	//temp ���ÿ� �ٽ� �־���
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