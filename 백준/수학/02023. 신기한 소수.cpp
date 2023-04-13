#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int first, int n) {
    //자릿수(n)가 0이 되면 그 수 출력
    if (n == 0) printf("%d\n", first);

    for (int i = 1; i < 10; i += 2) {   //홀수만 더해주기
        int tmp = first * 10 + i;
        if (isPrime(tmp)) {
            dfs(tmp, n - 1);
        }
    }

}
int main(void) {
    int n;
    scanf("%d", &n);

    //맨 앞 자릿수가 prime number 이어야합니다
    int prime[4] = { 2, 3, 5, 7 };
    for (int i = 0; i < 4; i++) {
        dfs(prime[i], n - 1);
    }
    return 0;
}
