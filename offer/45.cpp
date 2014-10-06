#include <cstdio>

int main(){
    int n, m;
    scanf("%d", &n);
    while (n) {
        scanf("%d", &m);
        m--;
        int x = 0;
        for(int i = 2; i <= n; i++)
            x = (x + m%i + 1)% i;
        printf("%d\n", x+1);
        scanf("%d", &n);
    }
    return 0;
}
