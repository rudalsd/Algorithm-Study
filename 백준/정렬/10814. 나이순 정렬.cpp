#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int N;

struct node {
	int age;
	string name;
	int seq;
};

node arr[100000];

bool cmp(node left, node right)
{
	if (left.age == right.age) return left.seq < right.seq;
	return left.age < right.age;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		arr[i] = { age,name,i };
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].age << ' ' << arr[i].name << '\n';
	}
}