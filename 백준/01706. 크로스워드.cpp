#include<iostream>
#include<string>
#include<vector>
#include<algorithm>>

using namespace std;

char arr[101][101];
int R, C;
vector<string> bucket;

int find(string str, int num)									//알파벳을 찾으면 index를 반환
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
		start = find(str, end);								//단어의 시작 index 찾기
		if (start == -1) break;									//단어가 없으면 -1 반환
		end = str.find("#", start);							//단어의 끝 index 찾기
		if (end == -1) end = str.size();

		if (end - start > 1) {
			string tmp = str.substr(start, end - start);
			bucket.push_back(tmp);			//2글자 이상 단어면 bucket 벡터에 넣기
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
		words(temp);											//원래 배열
	}
	for (int i = 0; i < C; i++) {
		string temp = "";
		for (int j = 0; j < R; j++) {
			temp += arr[j][i];
		}
		words(temp);
	}

	sort(bucket.begin(), bucket.end());							//정렬

	cout << bucket[0];
}