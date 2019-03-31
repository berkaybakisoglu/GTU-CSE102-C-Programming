#include <stdio.h>
#include <string.h>
#include <math.h>//pow
#include "sfrac.h"

int main(){
	char n1[100];
	char n2[100];
	char operation,junk;
	double x=33;
	printf("Input your operation line by line: ");
	gets(n1);
	scanf(" %c%c",&operation,&junk);//junk for enter
	gets(n2);
	if(operation=='+')
		sfrac_add(n1,n2);
	else if(operation=='-')
		sfrac_sub(n1,n2);
	else if(operation=='*')
		sfrac_mult(n1,n2);
	else if(operation==':')
		sfrac_div(n1,n2);
		return 0;
}
