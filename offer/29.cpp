#include <cstdio>

int arr[100001];

int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        int cnt = 0, ret, tmp;
        for(int i = 0; i < n; i ++){
            scanf("%d", &tmp);
            arr[i] = tmp;
            if(cnt == 0){
                ret = tmp;
                cnt++;
            } else if (tmp == ret){
                cnt++;
            } else {cnt--;
            }
        }
        tmp = 0;
        for( int i = 0; i < n; i++)
            if(arr[i] == ret)
                tmp++;
        if(tmp <= n/2)
            ret = -1;
        printf("%d\n", ret);
    }
}
