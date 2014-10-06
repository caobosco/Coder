#include <cstdio>

int arr[1000001];

int min_in_order(int arr[], int l, int r){
    int ret = arr[l];
    for(int i = l+ 1; i < r; ++i){
        if(ret > arr[i])
            ret = arr[i];
    }
    return ret;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int l = 0, r = n;
        while(l < r) {
            int mid = (l+ r)/2;
            if(mid == 0){
                printf("%d\n", arr[mid]);
                break;
            }
            else if (arr[mid] == arr[l] && arr[mid] == arr[r- 1]){
                printf("%d\n", min_in_order(arr, l, r));
                break;
            }
            else if(arr[mid] < arr[mid- 1]) {
                printf("%d\n", arr[mid]);
                break;
            }
            else if( arr[mid] > arr[l]) l = mid + 1;
            else r = mid;
        }
        if( l == r)
            printf("%d\n", arr[0]);
    }
    return 0;
} 
