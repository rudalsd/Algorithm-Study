#include <iostream>

using namespace std;

int NUM[101];
int ans[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, token, N;
    int count = 1, from = 0, value;
    
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> token;
        NUM[i] = token;
    }

    ans[0] = NUM[0];

    cout << N << '\n';

    int cur = 0;

    while (count < N) {
        value = ans[cur];
        cur = (cur + value) % N;
        while (ans[cur] != 0) cur = (cur + 1) % N;
        ans[cur] = NUM[count];
        count++;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
}
