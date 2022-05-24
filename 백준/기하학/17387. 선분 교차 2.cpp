#include <iostream>
#include <algorithm>

using namespace std;

struct pos {
    long long x;
    long long y;
};

pos arr[4];

bool cmp(pos left, pos right)
{
    if (left.x == right.x) return left.y <= right.y;
    return left.x <= right.x;
}

int closs(pos p1, pos p2, pos p3) {         //외적을 통해 방향을 리턴
    long long cross_product = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

    if (cross_product > 0) {
        return 1;
    }
    else if (cross_product < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int main()
{
    for (int i = 0; i < 4; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + 2, cmp);
    sort(arr + 2, arr + 4, cmp);
    int l1 = closs(arr[0], arr[1], arr[2]) * closs(arr[0], arr[1], arr[3]);
    int l2 = closs(arr[2], arr[3], arr[0]) * closs(arr[2], arr[3], arr[1]);
    if (l1 == 0 && l2 == 0) {            //두 선이 일직선상에 있을 때
        if (cmp(arr[2], arr[1]) && cmp(arr[0], arr[3])) {
            cout << 1;
            return 0;
        }
    }
    else if (l1 <= 0 && l2 <= 0) {
        cout << 1;
        return 0;
    }

    cout << 0;
}