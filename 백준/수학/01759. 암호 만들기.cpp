#include<iostream>
#include<algorithm>

using namespace std;

int L, C;
char arr[15];
char ans[16];

bool check()
{
	int con, vow;

	con = vow = 0;

	for (int i = 0; i < L; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
			vow++;
		}
		else {
			con++;
		}
	}

	if (vow > 0 && con > 1) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int level, int a)
{
	if (level == L) {
		if (check()) {
			printf("%s\n", ans);
		}
		return;
	}

	for (int i = a; i < C; i++) {
		ans[level] = arr[i];
		dfs(level + 1, i + 1);
	}
}

int main()
{
	scanf("%d %d", &L, &C);

	for (int i = 0; i < C; i++) {
		getchar();
		char ch;
		scanf("%c", &ch);
		arr[i] = ch;
	}

	sort(arr, arr + C);

	dfs(0, 0);
}