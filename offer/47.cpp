#include <cstdio>

int add(int a, int b) {
    int curSum = a^b;
    int carry = a&b;
    if( !carry)
        return curSum;
    return add(curSum, carry<<1);
}

int main(){
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF)
        printf("%d\n", add(m, n));
    return 0;
}    
