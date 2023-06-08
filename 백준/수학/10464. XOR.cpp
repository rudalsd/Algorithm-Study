#include<iostream>

using namespace std;

int XOR(int num)
{
	int mod = num % 4;

	if (mod == 0) return num;
	if (mod == 1) return 1;
	if (mod == 2) return num + 1;
	if (mod == 3) return 0;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int S, F;
		scanf("%d %d", &S, &F);
		
		printf("%d\n", XOR(S - 1) ^ XOR(F));
	}
}
