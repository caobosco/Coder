#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]){
	printf("The number of parameter is %d.", argc);
	if(argc != 3){
		printf("The number of parameter is incorrect. You need to input to positive number");
		return 1;
		}
	int base = atoi(argv[1]);
	int num = atoi(argv[2]);
	if(num > base)
		return 1;
	long long int res = base;
	for( int i = 1; i != num; i++){
		res *= (base - i);
		res /= i;
	}
	res /=num;
	printf("The result is %lld.", res);
	return 0;
}
