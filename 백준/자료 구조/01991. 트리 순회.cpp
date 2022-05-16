#include<iostream>

using namespace std;
int list[27][2];

void preorder(int cur)
{
	if (cur == '.')
		return;

	cout << (char)cur;
	preorder(list[cur - 'A'][0]);
	preorder(list[cur - 'A'][1]);
}

void inorder(int cur)
{
	if (cur == '.')
		return;


	inorder(list[cur - 'A'][0]);
	cout << (char)cur;
	inorder(list[cur - 'A'][1]);
}

void postorder(int cur)
{
	if (cur == '.')
		return;

	postorder(list[cur - 'A'][0]);
	postorder(list[cur - 'A'][1]);
	cout << (char)cur;
}

int main()
{
	int num;
	cin >> num;
	char root;
	char left;
	char right;

	for (int i = 0; i < num; i++)
	{
		cin >> root >> left >> right;
		list[root - 'A'][0] = left;
		list[root - 'A'][1] = right;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');

	return 0;
}