#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
	int a, b, c;
};

bool cmp(node left, node right)
{
	return left.c < right.c;
}

int N;
vector<node> arr;
int vect[51];
int ans;

int Find(int num)
{
	if (vect[num] == num) return num;
	return vect[num] = Find(vect[num]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	vect[pb] = pa;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		char temp[55];
		scanf("%s", temp);
		for (int j = 1; j <= N; j++) {
			if (temp[j - 1] >= 'a' && temp[j - 1] <= 'z') {
				arr.push_back({ i,j, temp[j - 1] - 'a' + 1 });
				ans += temp[j - 1] - 'a' + 1;
			}
			else if (temp[j - 1] >= 'A' && temp[j - 1] <= 'Z') {
				arr.push_back({ i,j,temp[j - 1] - 'A' + 27 });
				ans += temp[j - 1] - 'A' + 27;
			}
		}

		vect[i] = i;
	}

	sort(arr.begin(), arr.end(), cmp);

	int cnt = 0;

	for (auto& next : arr) {
		const int a = next.a;
		const int b = next.b;
		const int c = next.c;

		if (Find(a) != Find(b)) {
			Union(a, b);
			ans -= c;
			cnt++;
		}
	}

	if (cnt != N - 1) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}
}