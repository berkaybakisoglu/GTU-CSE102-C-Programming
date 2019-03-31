/*
*********************************************
* Berkay Bakışoğlu 141044061 homework2 part2*
*
*********************************************
*/
#include <stdio.h>
#include <math.h> //pow for calculate power.
int main(){
	int degree,junk,place,x,total=0,i,cb,min,max,count=0;
	FILE* fp;
	fp=fopen("polynomial.txt","r");
	if(fp==NULL){
		printf("File cannot be opened");return 0;
	}
	while(!feof(fp)){
		count++;
	fscanf(fp,"%d",&degree); 
	place=ftell(fp); //after takes degree,save byte of it to turn back
	for(i=0;i<=degree;++i){ //jump to take x
		fscanf(fp,"%d",&junk);
	}
	fscanf(fp,"%d",&x);
	rewind(fp); // jump back to start of file
	fseek(fp,place,SEEK_SET); // jump to degree of polynom back
	for(i=degree;i>=0;i--){ //takes coefficients
			//printf("%d %d %d \n",i,cb,x);
			fscanf(fp,"%d",&cb);
			total+=(cb)*pow(x,i);
}
printf("Polynomial %d = %d\n",count,total);
	if(count==1){ //min and max equals to 1st polynomial's result to compare
		max=total;
		min=total;
	}
	if(total>max){
		max=total;
}
	else if(total<min){
		min=total;
}
	total=0;
	fscanf(fp,"%d",&junk); // for skip a readed int
}
printf("max=%d\nmin=%d\n",max,min);
}
