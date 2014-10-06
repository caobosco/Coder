#include <cstdio>

int arr[10001];

bool is_result(int start, int end) {
    if(start >= end)
        return 1;
    int mid = start;
    while(arr[mid] < arr[end])
        mid++;
    int pos = mid;
    while(pos < end) {
        if (arr[pos] < arr[end])
            return 0;
        pos++;
    }
    return is_result(start, mid -1) && is_result(mid, end- 1);
} 

int main(){
    int n;
    while(scanf("%d", &n) !=EOF) {
        for(int i = 0 ; i < n; ++i) 
            scanf("%d", &arr[i]);
        if(is_result(0, n-1))
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}
        
