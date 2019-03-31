#include <stdio.h>
	
	int main(){
		int count=0;
		double i=0,average;
		char letter;

		printf("Please enter your grade \n");
		
		while(i!=-1){
			scanf("%lf",&i);
			if(i>=90){
					printf("Letter grade:A \n");
			}
			else if(i>=80){
					printf("Letter grade:B \n");
			}
			else if(i>=70){
					printf("Letter grade:C \n");
			}
			else if(i>=60){
					printf("Letter grade:D \n");
			}
			else{
					printf("Letter grade:F \n");
			}
			++count;
			average+=i;
			if(i==-1){
				count-=1;
				average+=1;
			}
		
		}

			if(average!=0)
				average=average/count;
			else //Error case
				average=0;
				
			if(average>=90){
				letter='A';
			}
			else if(average>=80){
				letter='B';
			}
			else if(average>=70){
				letter='C';
			}
			else if(average>=60){
				letter='D';
			}
			else{
				letter='F';
			}
			printf("%.1lf %c",average,letter);

		
	}

