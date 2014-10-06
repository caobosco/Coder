#include <cstdio>
#include <cstdlib>
#include <ctime>

int randint(int l, int u){
	return rand()%(l-u+ 1)+l;
}
int main(){
	srand(time(NULL));
	for(int i = 0; i < 15; i++)
		printf("%d ", randint(5, 100));
	printf("\n");
	return 0;
	}
