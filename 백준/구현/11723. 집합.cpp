#include<iostream>
#include<cstring>

using namespace std;

int M;
int arr[21];

int main()
{
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		char input[10] = { 0 };
		int num;
		scanf("%s", input);

		if (!strcmp(input, "add")) {
			scanf("%d", &num);
			arr[num] = 1;
		}
		else if (!strcmp(input, "remove")) {
			scanf("%d", &num);
			arr[num] = 0;
		}
		else if (!strcmp(input, "check")) {
			scanf("%d", &num);
			printf("%d\n", arr[num]);
		}
		else if (!strcmp(input, "toggle")) {
			scanf("%d", &num);
			if (arr[num] == 1) arr[num] = 0;
			else arr[num] = 1;
		}
		else if (!strcmp(input, "all")) {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}
		else {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}
	}
}