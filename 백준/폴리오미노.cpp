#include<iostream>
#include<string>

using namespace std;

string board;

int main()
{
	cin >> board;
	board += '.';
	int cnt = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 'X')cnt++;
		else if (board[i] == '.') {
			while (1) {
				if (cnt >= 4) {
					for (int j = 0; j < 4; j++) {
						board[i - cnt + j] = 'A';
					}
					cnt -= 4;
				}
				else if (cnt >= 2) {
					for (int j = 0; j < 2; j++) {
						board[i - cnt + j] = 'B';
					}
					cnt -= 2;
				}
				else if (cnt == 1) {
					cout << -1;
					return 0;
				}
				else
					break;
			}
		}
	}
	for (int i = 0; i < board.size() - 1; i++) {
		cout << board[i];
	}
}