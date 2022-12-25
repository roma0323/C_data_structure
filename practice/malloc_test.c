#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


	
int main()
{   
    printf("sdcsdcsdcs\n");
    int *pp,*aa;
    pp = (int*)malloc(sizeof(int));
    aa = (int*)malloc(sizeof(int));
    *pp = 5;
    *aa = 7;
	printf("%daa:\n",*aa);
    printf("%dpp:\n",*pp);
    aa=pp;
    printf("%daa:\n",*aa);
    printf("%dpp:\n",*pp);	
	return 0;
}
