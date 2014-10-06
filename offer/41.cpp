#include <cstdio>

int main(){
    int num, target;
    int ret1, ret2;
    while(scanf("%d %d", &num, &target) != EOF) {
        int *arr = new int[num];
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        int l = 0, r = num-1;
        bool flg = 0;
        while(l < r){
            if(arr[l] + arr[r] == target) {
                if(!flg){
                    ret1 = arr[l];
                    ret2 = arr[r];
                    flg = 1;
                }
                else if(arr[l]*arr[r] < ret1*ret2){
                    ret1 = arr[l];
                    ret2 = arr[r];
                }
                l++, r--;
            }
            if(arr[l] + arr[r] > target)
                r--;
            else l++;
        }        
        delete[] arr;
        if(!flg)
            ret1= ret2= -1;
        printf("%d %d\n", ret1, ret2);
    }
    return 0;
}
