#include <iostream>
#include <cstdio>

int arr[100];

int main(){
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for(int i = 0; i < n; ++i) 
            scanf("%d", &arr[i]);
        int index = 0, val, pos, tmp, cnt = 0;
        while(cnt < n) {
            pos = (n+ index- k)%n;
            val = arr[index];
            while(pos != index) {
                tmp = arr[pos];
                arr[pos] = val;
                val = tmp;
                pos = (n+ pos- k)%n;
                cnt++;
            }
            arr[index] = val;
            index++,cnt++;
        }
        printf("%d", arr[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", arr[i]);
        putchar('\n');
    }
    return 0;
}
