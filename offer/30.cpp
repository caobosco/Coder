#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[200001];
int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        for(int i = 0; i < k; ++i)
            scanf("%d", &arr[i]);
        make_heap(arr, arr+k);
       
        int tmp;
        for(int i = k; i < n; ++i){
            scanf("%d", &tmp);
            if(tmp < arr[0]){
                pop_heap(arr, arr+k);
                arr[k-1] = tmp;
                push_heap(arr, arr+ k);
            }
        }

        sort_heap(arr, arr+ k);
        for(int i = 0; i < k; ++i)
            printf("%d ", arr[i]);
        putchar('\n');
    }
    return 0;
} 
