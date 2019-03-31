#include <stdio.h>
#define PI 3.14
double sine (); //calculates value of sine with taylor series
double mathFactorial(int y); // finds factorial of y
double mathPow(double x, double y); //finds y power of x
int main(){
part1();
}
int part1(void){
	return	sine();
}
double sine ()
{
	int degree,n;
	double a, b, c, d, e,result=0,radian;
	
	printf("Please enter angle as degree ");
	if(!(scanf("%d",&degree)==1)){
		printf("You have entered non integer degree \n");
		return 1;
	}
	printf("Please enter number of terms ");
	if(!(scanf("%d",&n)==1)){
		printf("You have entered non integer n\n");
		return 1;
	}
	if(n<=0){
		printf("N cant be under 1");
		return 1;
	}
	degree%=360;
	if(degree>=180 &&degree<=360){
		degree=180-degree;
	}
	else if(degree<=-180 &&degree>=-360)
		degree=360+degree;
	radian = degree * (PI / 180);
	while(n >= 0)
	{
		a = mathPow((-1),n);
		b = mathPow(radian,((2 * n) + 1));
		c = a * b;
		d = mathFactorial((2 * n) + 1);
		e = c / d;
		result = result + e;
		n--;
	}
	printf("Value of sine is %.4lf \n",result);
	return 0;
}
double mathFactorial(int x)
{
	double a = 1, result = 1;
	while (a <= x)
	{
		result = a * result; 
		a++;
	}
	return result;
}

double mathPow(double x,double y){
	int i;
	double result=1;
	if(y<=0){
		y=-y;
		if(x==0 && y==0)
			printf("Undefined power.");
		else if(y==0)
			result=1;
		else if(x==0)
			result=0;
		else{
		for(i=0;i<y;++i){
			result=result*x;
		}
	}
	return 1/result;
}
	else {
		if(x==0)
			result=0;
		else{
		for(i=0;i<y;++i){
			result=result*x;
		}
	}
	return result;
}
}
			
			
