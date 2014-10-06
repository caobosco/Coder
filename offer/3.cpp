#include <cstdio>

int main(){
    int col, row, target;
    int arr[1001][1001];
    while(scanf("%d %d %d", &col, &row, &target) != EOF){
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int c = col -1;
        int r = 0;
        bool flg = 1;
        while(c >= 0 && r < row){
            if(arr[c][r] == target){
                printf("Yes\n");
                flg = 0;
                break;
            }
            else if (arr[c][r] > target)
                c--;
            else r++;
        }
        if(flg)
            printf("No\n");
    }
    return 0;
}    
