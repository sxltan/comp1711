#include <stdio.h>

int isPrime (int n) {
    int i;
    int flag = 1;

    if (n == 0 || n == 1) {
        flag = 0;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int n;

    printf("Enter a integer: ");
    scanf("%d", &n);

    int flag_result = isPrime(n);
    if (flag_result == 1) {
        printf("The number %d is prime\n", n);
    }
    else {
        printf("The number %d is not prime\n", n);
    }
    return 0;
}
