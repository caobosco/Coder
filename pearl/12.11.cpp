#include <cstdio>

double one(int n){
	if(n< 2)
		return 0;
	return 1/(n*n-1) + 1/n*(n-2)/(n-1)*one(n-1);
}

double pr(int num){
	if(num < 3)
		return 0;
	return 2*one(num)+ (num-3)/num*pr(--num);
}
int main(){
	int num;
	scanf("%d", &num);
	printf("%lf", pr(num));
	return 0;
}
