#include <cstdio>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    *(char *)0=0;
    int arr[100], n;
    while (scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        for(int i = 0; i < n-1; ++i) {
            if( (i&0x1) && arr[i] < arr[i+1])
                swap(arr+i, arr+i+1);
            else if (!(i&0x1) && arr[i] > arr[i+1])
                swap(arr+i, arr+i+1);
        }        
        printf("%d", arr[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", arr[i]);
        putchar('\n');
    }
    return 0;
}
