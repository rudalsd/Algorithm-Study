#include<iostream>
#include<vector>

using namespace std;

int arr[6][3];
int result[4];
int temp[6][3];
vector<pair<int, int>> p;
bool res;

void dfs(int level)
{
	if (level == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != temp[i][j]) {
					return;
				}
			}
		}
		res = true;
		return;
	}

	const int a = p[level].first;
	const int b = p[level].second;

	//a 승
	temp[a][0]++;
	temp[b][2]++;
	dfs(level + 1);
	temp[a][0]--;
	temp[b][2]--;

	//무
	temp[a][1]++;
	temp[b][1]++;
	dfs(level + 1);
	temp[a][1]--;
	temp[b][1]--;

	//패
	temp[a][2]++;
	temp[b][0]++;
	dfs(level + 1);
	temp[a][2]--;
	temp[b][0]--;
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			p.push_back({ i,j });
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				scanf("%d", &arr[j][k]);
			}
		}
		res = false;

		dfs(0);

		if (res == true) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}
	}


}