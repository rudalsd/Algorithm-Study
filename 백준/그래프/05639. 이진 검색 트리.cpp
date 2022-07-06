#include<iostream>

using namespace std;

int arr[10000];
int i;

void dfs(int node, int size)
{
	if (node >= size) return;

	for (i = node + 1; i < size; i++) {
		if (arr[node] < arr[i]) break;
	}

	dfs(node + 1, i);	//왼쪽
	dfs(i, size);		//오른쪽
	printf("%d\n", arr[node]);

	return;
}

int main()
{
	int idx = 0;

	while (scanf("%d", &arr[idx]) != EOF)
	{
		idx++;
	}

	dfs(0, idx);
}
