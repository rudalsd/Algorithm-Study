#include<iostream>
#include<string>

using namespace std;

void turn(char a, string side[3])	//¸é È¸Àü
{
	string temp[3] = {
		"aaa","bbb","ccc"
	};
	if (a == '+') {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[j][2 - i] = side[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = side[j][2 - i];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		side[i] = temp[i];
	}
}

void change(char* input, string cube[][3])
{
	if (input[0] == 'U') {		//À­ ¸é
		string temp = cube[3][0];
		if (input[1] == '-') {
			turn('-', cube[0]);
			cube[3][0] = cube[5][0];
			cube[5][0] = cube[2][0];
			cube[2][0] = cube[4][0];
			cube[4][0] = temp;
		}
		else {
			turn('+', cube[0]);
			cube[3][0] = cube[4][0];
			cube[4][0] = cube[2][0];
			cube[2][0] = cube[5][0];
			cube[5][0] = temp;
		}
	}
	else if (input[0] == 'D') {		//¾Æ·§ ¸é
		string temp = cube[3][2];
		if (input[1] == '-') {
			turn('-', cube[1]);
			cube[3][2] = cube[4][2];
			cube[4][2] = cube[2][2];
			cube[2][2] = cube[5][2];
			cube[5][2] = temp;
		}
		else {
			turn('+', cube[1]);
			cube[3][2] = cube[5][2];
			cube[5][2] = cube[2][2];
			cube[2][2] = cube[4][2];
			cube[4][2] = temp;
		}
	}
	else if (input[0] == 'F') {	//¾Õ ¸é
		string temp = cube[0][2];
		if (input[1] == '-') {
			turn('-', cube[2]);
			for (int i = 0; i < 3; i++) {
				cube[0][2][i] = cube[5][i][0];
				cube[5][i][0] = cube[1][2][i];
				cube[1][2][i] = cube[4][2 - i][2];
				cube[4][2 - i][2] = temp[i];
			}
		}
		else {
			turn('+', cube[2]);
			for (int i = 0; i < 3; i++) {
				cube[0][2][i] = cube[4][2 - i][2];
				cube[4][2 - i][2] = cube[1][2][i];
				cube[1][2][i] = cube[5][i][0];
				cube[5][i][0] = temp[i];
			}
		}
	}
	else if (input[0] == 'B') {	//µÞ ¸é
		string temp = cube[0][0];
		if (input[1] == '-') {
			turn('-', cube[3]);
			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = cube[1][0][i];
				cube[1][0][i] = cube[5][i][2];
				cube[5][i][2] = temp[i];
			}
		}
		else {
			turn('+', cube[3]);
			for (int i = 0; i < 3; i++) {
				cube[0][0][i] = cube[5][i][2];
				cube[5][i][2] = cube[1][0][i];
				cube[1][0][i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = temp[i];
			}
		}
	}
	else if (input[0] == 'L') {	//¿ÞÂÊ ¸é
		string temp = "";
		for (int i = 0; i < 3; i++) {
			temp += cube[0][i][0];
		}

		if (input[1] == '-') {
			turn('-', cube[4]);
			for (int i = 0; i < 3; i++) {
				cube[0][i][0] = cube[2][i][0];
				cube[2][i][0] = cube[1][2 - i][2];
				cube[1][2 - i][2] = cube[3][2 - i][2];
				cube[3][2 - i][2] = temp[i];
			}
		}
		else {
			turn('+', cube[4]);
			for (int i = 0; i < 3; i++) {
				cube[0][i][0] = cube[3][2 - i][2];
				cube[3][2 - i][2] = cube[1][2 - i][2];
				cube[1][2 - i][2] = cube[2][i][0];
				cube[2][i][0] = temp[i];
			}
		}
	}
	else {	//¿À¸¥ÂÊ ¸é
		string temp = "";
		for (int i = 0; i < 3; i++) {
			temp += cube[0][i][2];
		}

		if (input[1] == '-') {
			turn('-', cube[5]);
			for (int i = 0; i < 3; i++) {
				cube[0][2 - i][2] = cube[3][i][0];
				cube[3][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[2][2 - i][2];
				cube[2][2 - i][2] = temp[2 - i];
			}
		}
		else {
			turn('+', cube[5]);
			for (int i = 0; i < 3; i++) {
				cube[0][2 - i][2] = cube[2][2 - i][2];
				cube[2][2 - i][2] = cube[1][i][0];
				cube[1][i][0] = cube[3][i][0];
				cube[3][i][0] = temp[2 - i];
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		string cube[6][3] = {	//Å¥ºê ÃÊ±âÈ­
			{"www", "www", "www"},
			{"yyy", "yyy", "yyy"},
			{"rrr",	"rrr", "rrr"},
			{"ooo",	"ooo", "ooo"},
			{"ggg",	"ggg", "ggg"},
			{"bbb",	"bbb", "bbb"}
		};
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			char input[5];
			scanf("%s", input);
			change(input, cube);
		}

		for (int i = 0; i < 3; i++) {
			cout << cube[0][i] << endl;
		}
	}
}