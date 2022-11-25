#include<iostream>

using namespace std;

int main()
{
    unsigned int a, b;
    unsigned int cur;
    scanf("%d %d", &a, &b);
    cur = b - a;

    int ans = 0;

    if (cur < 1) {
        printf("%d", 0);
        return 0;
    }

    while (ans * ans < cur) {
        ans++;
    }

    if (ans * ans - ans < cur) {
        printf("%d", ans * 2 - 1);
    }
    else {
        printf("%d", ans * 2 - 2);
    }
}