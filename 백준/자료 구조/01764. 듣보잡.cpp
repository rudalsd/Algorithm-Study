#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<string, int> ma;
    vector<string> vt;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++) {
        string str;
        cin >> str;
        ma[str]++;
        if (ma[str] > 1)
            vt.push_back(str);
    }
    sort(vt.begin(), vt.end());
    cout << vt.size() << '\n';
    for (auto o : vt)
        cout << o << '\n';

}