#include "time.h"
#include "stdio.h"
#include <sys/time.h>

int main(){
	time_t a, b;
	struct timeval t1, t2;
	t1= get();
	a = time(NULL);
	for(int i = 0; i < (1<<10); i++)
		for(int j = 0; j < (1<< 20); j++);
	b = time(NULL);
	
	t2 = GetTickCount();
	printf("%ld\n", b- a);
	printf("%ld\n", t2- t1);
	return 0;
}
