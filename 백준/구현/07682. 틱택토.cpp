#include<iostream>
#include<string>
#include<cstring>
#include<unordered_map>

using namespace std;

char tik[10];
char temp[10] = ".........";
unordered_map<string, bool> m;

void dfs(int level)
{
	if (level == 9) {
		m[temp] = true;	//�ºΰ� ���� �ʾ��� ��
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (temp[i * 3] == temp[i * 3 + 1] && temp[i * 3 + 1] == temp[i * 3 + 2] && temp[i * 3] != '.') {	//����
			m[temp] = true;
			return;
		}
		if (temp[i] == temp[i + 3] && temp[i + 3] == temp[i + 6] && temp[i] != '.') {	//����
			m[temp] = true;
			return;
		}
	}
	if (((temp[0] == temp[4] && temp[4] == temp[8]) || (temp[2] == temp[4] && temp[4] == temp[6])) && temp[4] != '.') {	//�밢
		m[temp] = true;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (temp[i] == '.') {
			if (level % 2 == 0) {
				temp[i] = 'X';
				dfs(level + 1);
				temp[i] = '.';
			}
			else {
				temp[i] = 'O';
				dfs(level + 1);
				temp[i] = '.';
			}
		}
	}
}

int main()
{
	dfs(0);	//������ ����Ǽ� map�� ����

	while (1) {
		scanf("%s", &tik);
		if (!strcmp(tik, "end")) {
			return 0;
		}

		if (m[tik] == true) {
			printf("valid\n");
		}
		else {
			printf("invalid\n");
		}
	}
}