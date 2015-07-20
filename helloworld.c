#include <stdio.h>
int main()
{

	unsigned int a =0xfffffff7;
	unsigned char i = (unsigned char) a ;
	char *b =(char*) &a ;
	printf("%08x, %08x",i,*b );	
	fflush(stdout);
	while(1);
	return 0;
}