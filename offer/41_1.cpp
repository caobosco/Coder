#include <cstdio>
#include <cmath>

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
        if(num < 0)
            break;
        int len = sqrt(num*2);
        int plus = (len-1)*len/2;
        int rem = (num-plus)/len;
        bool flg = 0;
        while( len > 1) {
            if( (num - plus) %len == 0){
                flg = 1;
                printf("%d", rem);
                for(int i = 1; i< len;++i)
                    printf(" %d", ++rem);
                putchar('\n');
            }
            len--;
            plus = (len-1)*len/2;
            rem = (num-plus)/len;
        }
        if(!flg)
            printf("Pity!\n");
        printf("#\n");
    }
    return 0;
}
            
