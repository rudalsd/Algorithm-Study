#include<iostream>
#include<string>
#include<vector>
#include<algorithm>>

using namespace std;

char arr[101][101];
int R, C;
vector<string> bucket;

int find(string str, int num)									//���ĺ��� ã���� index�� ��ȯ
{
	for (int i = num; i < str.size(); i++)
	{
		if (str[i] <= 'z' && str[i] >= 'a') {
			return i;
		}
	}
	return -1;
}

void words(string str)
{
	int start = 0;
	int end = 0;
	while (1)
	{
		start = find(str, end);								//�ܾ��� ���� index ã��
		if (start == -1) break;									//�ܾ ������ -1 ��ȯ
		end = str.find("#", start);							//�ܾ��� �� index ã��
		if (end == -1) end = str.size();

		if (end - start > 1) {
			string tmp = str.substr(start, end - start);
			bucket.push_back(tmp);			//2���� �̻� �ܾ�� bucket ���Ϳ� �ֱ�
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < R; i++) {
		string temp = arr[i];
		words(temp);											//���� �迭
	}
	for (int i = 0; i < C; i++) {
		string temp = "";
		for (int j = 0; j < R; j++) {
			temp += arr[j][i];
		}
		words(temp);
	}

	sort(bucket.begin(), bucket.end());							//����

	cout << bucket[0];
}