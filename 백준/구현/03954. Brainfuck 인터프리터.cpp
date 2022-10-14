#include<iostream>
#include<stack>
#include<map>
#include<cstring>

#define M 256

using namespace std;

unsigned char arr[100000];
char cal[4097];
char input[4097];

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int sm, sc, si;
		scanf("%d %d %d", &sm, &sc, &si);

		stack<int> s;
		map<int, int> m;
		memset(arr, 0, sizeof(arr));
		scanf("%s", cal);
		scanf("%s", input);

		for (int i = 0; i < sc; i++) {
			if (cal[i] == '[') {
				s.push(i);
			}
			if (cal[i] == ']') {
				int temp = s.top();
				s.pop();
				m[temp] = i;
				m[i] = temp;
			}
		}

		int cnt = 0;	//연산 횟수
		int cur = 0;	//현재 포이터 위치
		int c = 0;		//현재 연산의 위치
		int in = 0;		//현재 문자열의 위치
		int Max = 0;

		while (1) {
			if (cnt > 50000000) {
				Max = max(Max, c);
			}
			if (cal[c] == '+') {
				arr[cur]++;
			}
			else if (cal[c] == '-') {
				arr[cur]--;
			}
			else if (cal[c] == '<') {
				cur--;
				if (cur < 0) {
					cur = sm - 1;
				}
			}
			else if (cal[c] == '>') {
				cur++;
				if (cur >= sm) {
					cur = 0;
				}
			}
			else if (cal[c] == '[') {
				if (arr[cur] == 0) {
					c = m[c];
				}
			}
			else if (cal[c] == ']') {
				if (arr[cur] != 0) {
					c = m[c];
				}
			}
			else if (cal[c] == ',') {
				if (in < si) {
					arr[cur] = input[in++];
				}
				else {
					arr[cur] = 255;
				}
			}
			c++;
			cnt++;
			if (c >= sc) {
				printf("Terminates\n");
				break;
			}
			if (cnt >= 100000000) {
				printf("Loops %d %d\n", m[Max], Max);
				break;
			}
		}
	}
}