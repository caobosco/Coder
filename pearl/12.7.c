#include <cstdio>
#include <ctime>
#include <cstdlib>


void randselect(int m, int l , int n){
	if(m < 1)
		return;
	if(rand()%(n- l) < m){
		printf("%d ", l);
		randselect(--m, ++l, n);
	}
	else randselect(m, ++l, n);
}

int main(){
	srand(time(NULL));
	randselect(15,0, 100);
	printf("\n");
	return 0;
}
