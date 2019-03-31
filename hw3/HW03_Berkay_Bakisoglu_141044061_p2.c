#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14
double derivative(int* x);
double derivative(int x); //overload
int main(){
	int x=90;
	int* px=&x;
	printf("%lf \n",derivative(x)); //call by value
	printf("%d \n",x);
	printf("%lf \n",derivative(px)); // Call by ref
	printf("%d \n",x);
}
double derivative(int* x){
	int count,i,k,j,a,ccheck=0;
	double total=0,rx=0;
	char elements[50][50];
	rx=*x*(PI/180);
	printf("Number of elements : ");
	if(!(scanf("%d",&count)))
		return 0;
	if(count<=0)
		return 0;
	for(i=0;i<count;++i){
		printf("The %d. element : ",i+1);
		scanf("%s",&elements[i]);
	}
	for(j=0;elements[0][j]!='\0' ||elements[0][j]!='.' ;++j){ //check constant
		if(elements[0][j]>='0' &&elements[0][j]<='9'){
			ccheck=1;
		}
		else{
			ccheck=0;
			break;
		}
	}
		if(ccheck==1)
		total=0;
		for(k=0;k<i;++k){
		if(strcmp(elements[k],"sin(x)")==0){
			total+=cos(rx);
		}
		else if(strcmp(elements[k],"cos(x)")==0){
			total-=sin(rx);
		}
		else if(strcmp(elements[k],"ln(x)")==0)
			total+=1/ *x;
		else if(strcmp(elements[k],"tan(x)")==0)
			total+=(1/cos(rx))*(1/cos(rx));
		else if(strcmp(elements[k],"sin^-1(x)")==0)
			total+=1/sqrt(1-pow(*x,2));
		else if(strcmp(elements[k],"cos^-1(x)")==0)
			total-=1/sqrt(1-pow(*x,2));
		else if(strcmp(elements[k],"tan^-1(x)")==0)
			total+=1/sqrt(1+pow(*x,2));
		else if(strcmp(elements[k],"x")==0)
			total+=1;
		else if(strcmp(elements[k],"x^1/2")==0)
			total+=(1/2)*(1/sqrt(*x));
}
	*x=total;
	return total;
}
double derivative(int x){
	int count,i,k,j,a,ccheck=0;
	double total=0,rx=0;
	char elements[50][50];
	rx=x*(PI/180);
	printf("Number of elements : ");
	scanf("%d",&count);
	for(i=0;i<count;++i){
		printf("The %d. element : ",i+1);
		scanf("%s",&elements[i]);
	}
	for(j=0;elements[0][j]!='\0' ||elements[0][j]!='.' ;++j){
		if(elements[0][j]>='0' &&elements[0][j]<='9'){
			ccheck=1;
		}
		else{
			ccheck=0;
			break;
		}
	}
		if(ccheck==1)
		total=0;
		for(k=0;k<i;++k){
		if(strcmp(elements[k],"sin(x)")==0){
			total+=cos(rx);
		}
		else if(strcmp(elements[k],"cos(x)")==0){
			total-=sin(rx);
		}
		else if(strcmp(elements[k],"ln(x)")==0)
			total+=1/ x;
		else if(strcmp(elements[k],"tan(x)")==0)
			total+=(1/cos(rx))*(1/cos(rx));
		else if(strcmp(elements[k],"sin^-1(x)")==0)
			total+=1/sqrt(1-pow(x,2));
		else if(strcmp(elements[k],"cos^-1(x)")==0)
			total-=1/sqrt(1-pow(x,2));
		else if(strcmp(elements[k],"tan^-1(x)")==0)
			total+=1/sqrt(1+pow(x,2));
		else if(strcmp(elements[k],"x")==0)
			total+=1;
		else if(strcmp(elements[k],"x^1/2")==0)
			total+=(1/2)*(1/sqrt(x));
}

	return total;
}
