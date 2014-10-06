#include "stdio.h"

int main(){
    for(unsigned int i = 100; i > 0; --i) {
        printf("%d ", i);
        printf("%u ", i);
    }
    return 0;
}
