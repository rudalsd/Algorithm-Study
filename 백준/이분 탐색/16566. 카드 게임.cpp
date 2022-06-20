#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int vect[4000001];
vector<int> card;
int N, M, K;

int Find(int num)
{
	if (vect[num] == num) return num;
	vect[num] = Find(vect[num]);
	return vect[num];
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if (pb != pa) {
		vect[pa] = pb;
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		card.push_back(num);
		vect[i] = i;
	}

	sort(card.begin(), card.end());

	for (int i = 0; i < K; i++) {
		int num;
		scanf("%d", &num);
		auto idx = upper_bound(card.begin(), card.end(), num) - card.begin();
		if (Find(idx) == idx) {		//카드를 쓰지 않았다면
			printf("%d\n", card[idx]);
		}
		else {						//카드를 썼다면
			printf("%d\n", card[Find(idx)]);
		}
		Union(Find(idx), Find(idx) + 1);
	}
}