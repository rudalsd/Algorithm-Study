#include<iostream>
#include<cstring>

using namespace std;

int lenS, lenP;
char S[1001];
char P[1001];

int main()
{
	scanf("%s %s", S, P);

	lenS = strlen(S);
	lenP = strlen(P);

	int cur = 0;
	int ans = 0;

	for (int i = 0; i < lenP; i++) {
		int Max = 0;
		for (int j = 0; j < lenS; j++) {
			int cnt = 0;
			int a = 0;
			while (S[j + a] == P[i + a]) {
				if (S[j + a] == 0) break;
				cnt++;
				a++;
			}
			Max = max(Max, cnt);
		}
		i += Max - 1;
		ans++;
	}

	printf("%d", ans);
}