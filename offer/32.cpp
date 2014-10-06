#include <cstdio>

int num_of_ones(int num) {
    if(num < 0)
        return 0;
    int tens = 1, rem, next, ret = 0;
    while(num/tens){
        rem = num%(tens*10)/tens; 
        next = num/tens/10;
        ret += next*tens;
        if(rem > 1)
            ret += tens;
        else if(rem == 1)
            ret += (num%tens + 1);
        tens *= 10;
    }
    return ret;
}
int main(){
    int a, b;
    while(scanf("%d %d", &a, &b)) {
        printf("%d\n", num_of_ones(b) - num_of_ones(a- 1)); 
    }
    return 0;
}
