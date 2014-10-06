#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, m, target;
    scanf("%d", &n);
    int *arr = new int[n];
    for(int i = 0; i < n; ++i) 
        scanf("%d", &arr[i]);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &target);
        printf("%d\n", upper_bound(arr, arr+n, target) - 
                    lower_bound(arr, arr+n, target));    
    }
    return 0;
}
