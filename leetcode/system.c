#include "stdlib.h"
#include "stdio.h"

int main(){
	system("ls -al");
	FILE * stream;
	char buf[200];
	stream = popen("lsusb", "r");
	fgets(buf, sizeof(buf), stream);
	printf("%s", buf);
	return 0;
}
