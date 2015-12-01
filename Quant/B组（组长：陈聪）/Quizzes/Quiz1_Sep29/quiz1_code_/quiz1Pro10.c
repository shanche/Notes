#include<stdio.h>
#define bool int

bool isPowerTwo (int n) {
    return n && (!(n & (n-1)));
}

int main() {
    isPowerTwo(16)? printf("yes\n"): printf("no\n");
    isPowerTwo(5)? printf("yes\n"): printf("no\n");
    return 0;
}