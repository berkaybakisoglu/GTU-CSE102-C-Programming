#include "sfrac.h"
int lcm(int i1,int i2){
	int i,lcm1;
	i=gcd(i1,i2);
    lcm1=(i1*i2)/i;
    return lcm1;
}
int gcd(int i1,int i2){
	int i,divisor=1;
	if(i1<0)
		i1=-i1;
	if(i2<0)
		i2=-i2;
	for(i=1;i<=i1 && i<=i2;++i)
    {
        if(i1%i==0 && i2%i==0)
            divisor=i;
    }
    return divisor;
}
char * sfrac_add(char *n1,char *n2){
	int numerator,denominator,numerator2,denominator2,tn,td,ctrl=0,ctrl2=0,i;
	char div='/';
	sscanf(n1,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n1[i]!='\0';++i)
		if(n1[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	sscanf(n2,"%d %c %d",&numerator2,&div,&denominator2);
	for(i=0;n2[i]!='\0';++i)
		if(n2[i]=='/'){
			ctrl2=1;
		}
	if(ctrl2==0)
		denominator2=1;
	if(denominator==denominator2){
		td=denominator;
		tn=numerator+numerator2;
	}
	else{
		numerator*=(lcm(denominator,denominator2)/denominator);
		numerator2*=(lcm(denominator,denominator2)/denominator2);
		td=lcm(denominator,denominator2);
		tn=numerator+numerator2;
	}
	sprintf(r,"%d %c %d",tn,div,td);
	strcpy(r,sfrac_simplify(r));
	printf("Result is: %s\n",r);
	return r;
}
char * sfrac_sub(char * n1, char * n2){
	int numerator,denominator,numerator2,denominator2,tn,td,ctrl=0,ctrl2=0,i;
	char div;
	sscanf(n1,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n1[i]!='\0';++i)
		if(n1[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	sscanf(n2,"%d %c %d",&numerator2,&div,&denominator2);
	for(i=0;n2[i]!='\0';++i)
		if(n2[i]=='/'){
			ctrl2=1;
		}
	if(ctrl2==0)
		denominator2=1;
	if(denominator==denominator2){
		td=denominator;
		tn=numerator-numerator2;
	}
	else{
		numerator*=(lcm(denominator,denominator2)/denominator);
		numerator2*=(lcm(denominator,denominator2)/denominator2);
		td=lcm(denominator,denominator2);
		tn=numerator-numerator2;
	}
	sprintf(r,"%d %c %d",tn,div,td);
	strcpy(r,sfrac_simplify(r));
	printf("Result is: %s\n",r);
	return r;
}
char * sfrac_negate(char * n){
	int numerator,denominator,i,ctrl=0;
	char div;
	sscanf(n,"%d %c %d",&numerator,&div,&denominator);
		for(i=0;n[i]!='\0';++i)
		if(n[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	numerator=-numerator;
	sprintf(n,"%d %c %d",numerator,div,denominator);
	return n;
}
char * sfrac_mult(char * n1, char * n2){
	int numerator,denominator,numerator2,denominator2,tn,td,ctrl=0,ctrl2=0,i;
	char div;
	sscanf(n1,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n1[i]!='\0';++i)
		if(n1[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	sscanf(n2,"%d %c %d",&numerator2,&div,&denominator2);
	for(i=0;n2[i]!='\0';++i)
		if(n2[i]=='/'){
			ctrl2=1;
		}
	if(ctrl2==0)
		denominator2=1;
	td=denominator*denominator2;
	tn=numerator*numerator2;
	sprintf(r,"%d %c %d",tn,div,td);
	strcpy(r,sfrac_simplify(r));
	printf("Result is %s\n",r);
	return r;
}
char * sfrac_div(char * n1, char * n2){
	int numerator,denominator,numerator2,denominator2,tn,td,ctrl=0,ctrl2=0,i;
	char div='/';
	sscanf(n1,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n1[i]!='\0';++i)
		if(n1[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	sscanf(n2,"%d %c %d",&numerator2,&div,&denominator2);
	for(i=0;n2[i]!='\0';++i)
		if(n2[i]=='/'){
			ctrl2=1;
		}
	if(ctrl2==0)
		denominator2=1;
	td=numerator2*denominator;
	tn=numerator2;
	sprintf(r,"%d %c %d",tn,div,td);
	strcpy(r,sfrac_simplify(r));
	printf("Result is: %s\n",r);
	return r;
}
char* sfrac_simplify(char * n){
	int numerator,denominator,td,tn,ctrl=0,i;
	char div;
	sscanf(n,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n[i]!='\0';++i)
		if(n[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
		if(numerator==0)
			sprintf(r,"%d",0);
		else{
	td=denominator/gcd(numerator,denominator);
	tn=numerator/gcd(numerator,denominator);
	sprintf(r,"%d %c %d",tn,div,td);
}
		return r;
}
char * sfrac_fromdouble(double x){
	int total,numerator,denominator,i,j=0,k,m;
	char div='/';
	sprintf(r,"%lf",x);
	for(i=0;r[i]!='\0';++i)
		if(r[i]=='.'){
			i++;
			break;
		}
	for(m=i;r[m]!='\0';++m){
		j++;
	}
	for(k=m-1;k>i-1;--k){
		if(r[k]=='0')
			--j;
		else
			break;		
	}
	numerator=x*pow(10,j);
	denominator=pow(10,j);	
	if(numerator==0){
		sprintf(r,"%d",0);
	}
	else{
	numerator=numerator/gcd(numerator,denominator);
	denominator=denominator/gcd(numerator,denominator);
	sprintf(r,"%d %c %d",numerator,div,denominator);
}
	printf("Result is: %s\n",r);
	return r;
}
double sfrac_todouble(char * x){
	int numerator,denominator,i,ctrl=0;
	double y;
	char div='/';
	sscanf(x,"%d%c%d",&numerator,&div,&denominator);
	for(i=0;x[i]!='\0';++i)
		if(x[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
	y=(double)numerator/denominator;
	printf("Result is: %lf\n",y);
	return y;
}
void sfrac_print(char *a1, char *n1, char *a2, char *n2, char *a3, char *n3, char *a4){
	int numerator=0,denominator=0,numerator2=0,denominator2=0,numerator3=0,denominator3=0;
	int ctrl=0,ctrl2=0,ctrl3=0,i,c1=0,c2=0,c3=0,temp,space;
	char div='/';
	printf("%s",a1);
	sscanf(n1,"%d %c %d",&numerator,&div,&denominator);
	for(i=0;n1[i]!='\0';++i)
		if(n1[i]=='/'){
			ctrl=1;
		}
	if(ctrl==0)
		denominator=1;
		temp=denominator;
	while(temp!=0){
		temp/=10;
		++c1;
	}
	for(i=1;i<c1;++i)
		printf(" ");
	printf("%d ",numerator);
	sscanf(n2,"%d %c %d",&numerator2,&div,&denominator2);
	for(i=0;n2[i]!='\0';++i){
		if(n2[i]=='/'){
			ctrl2=1;
		}}
	if(ctrl2==0)
		denominator2=1;
	temp=denominator2;
	while(temp!=0){
		temp/=10;
		++c2;
	}

	printf("%s ",a2);
	for(i=1;i<c2;++i)
		printf(" ");
	printf("%d ",numerator2);
	sscanf(n3,"%d %c %d",&numerator3,&div,&denominator3);
	for(i=0;n3[i]!='\0';++i){
		if(n3[i]=='/'){
			ctrl3=1;
		}}
	if(ctrl3==0)
		denominator3=1;
	temp=denominator3;
	while(temp!=0){
		temp/=10;
		++c3;
	}
	printf("%s",a3);
	for(i=1;i<c3;++i)
		printf(" ");
	printf("%d ",numerator3);
	printf("%s \n",a4);
	space=strlen(a1);
	for(i=0;i<space;++i)
		printf(" ");
	for(i=0;i<c1;++i)
		printf("-");
	printf(" ");
	space=strlen(a2);
	for(i=0;i<=space;++i)
		printf(" ");
	for(i=0;i<c2;++i)
		printf("-");
	space=strlen(a3);
	for(i=0;i<=space;++i)
		printf(" ");
	for(i=0;i<c3;++i)
		printf("-");
	printf(" \n");
	space=strlen(a1);
	for(i=0;i<space;++i)
		printf(" ");
	printf("%d ",denominator);
	space=strlen(a2);
	for(i=0;i<=space;++i)
		printf(" ");
	printf("%d",denominator2);
	space=strlen(a3);
	for(i=0;i<=space;++i)
		printf(" ");
	printf("%d",denominator3);
}}
