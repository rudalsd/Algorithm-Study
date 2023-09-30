#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N;
string arr[10000];

bool cmp(string left, string right)
{
	if (left == right) return false;

	int l = 0, r = 0;
	while (1) {
		if (l == left.size()) {
			return true;
		}
		if (r == right.size()) {
			return false;
		}

		if (left[l] <= '9' && right[r] <= '9') {
			int sizeL = 0, sizeR = 0;
			string L, R;
			bool zeroL = false, zeroR = false;
			while (left[l] <= '9' && l < left.size()) {
				if (left[l] != '0' && zeroL == false) {
					zeroL = true;
				}
				
				if (zeroL) {
					L += left[l];
				}

				l++;
				sizeL++;
			}

			while (right[r] <= '9' && r < right.size()) {
				if (right[r] != '0' && zeroR == false) {
					zeroR = true;
				}

				if (zeroR) {
					R += right[r];
				}
				r++;
				sizeR++;
			}

			if (R == L) {
				if (sizeL != sizeR) {
					return sizeL < sizeR;
				}
			}
			else {
				if (L.size() == R.size()) {
					for (int i = 0; i < L.size(); i++) {
						if (L[i] != R[i]) {
							return L[i] < R[i];
						}
					}
				}
				return L.size() < R.size();
			}
			continue;
		}
		
		if (left[l] != right[r]) {
			if (left[l] >= 'a') {
				if (right[r] >= 'a') {
					return left[l] < right[r];
				}
				else if (right[r] >= 'A') {
					return left[l] - 'a' < right[r] - 'A';
				}
				else {
					return false;
				}
			}
			else if (left[l] >= 'A') {
				if (right[r] >= 'a') {
					return left[l] - 'A' <= right[r] - 'a';
				}
				else if (right[r] >= 'A') {
					return left[l] < right[r];
				}
				else {
					return false;
				}
			}
			else {
				if (right[r] >= 'A') {
					return true;
				}
			}
		}

		l++;
		r++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
}