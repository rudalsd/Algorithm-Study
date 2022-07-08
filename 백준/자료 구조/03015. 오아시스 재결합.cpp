#include<iostream>
#include<stack>

using namespace std;

int N;

struct node {
	int num;	//Ű
	int cnt;	//�پ��ִ� ���� Ű�� ���� ���
};

int main()
{
	cin >> N;

	stack<node> s;

	long long ans = 0;

	for (int i = 0; i < N; i++) {
		int cur;
		scanf("%d", &cur);
		int cnt = 1;

		while (!s.empty() && s.top().num < cur) {	//�ٷ� �ջ���� Ű���� ���� Ű�� �� Ŭ ��
			ans += s.top().cnt;
			s.pop();
		}
		if (!s.empty()) {	//stack�� ������� ���� ��
			if (s.top().num == cur) {	//�ջ���� ������ Ű�� ���� ��
				ans += s.top().cnt;		//�տ� ���� Ű�� ���� ��� ����ŭ ans�� ������
				cnt = s.top().cnt + 1;	//���縦 �����ؼ� ���� Ű�� ���� ��� + 1
				if (s.size() > 1) {		//���� Ű�� ���� ����� ���� ū ����� �����ϸ�
					ans++;
				}
				s.pop();
			}
			else {	//�ջ���� ������ Ű���� Ŭ ��
				ans++;
			}
		}

		s.push({ cur, cnt });
	}

	cout << ans;
}