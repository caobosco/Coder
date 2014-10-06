#include <cstdio>

int main(){
    int ret = 0;
    for (int i = 1000; i > 2; i--)
        if (i %3 == 0 || i %5 == 0)
            ret += i;
    printf("%d", ret);
    return 0;
} 
