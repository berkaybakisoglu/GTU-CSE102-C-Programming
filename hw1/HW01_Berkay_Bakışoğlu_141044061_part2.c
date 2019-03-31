#include <stdio.h>

int main(){
	int fnumber,number,total=0;	
	char operation='a';

	scanf("%d",&number);
	//If user doesnt enter another number,then first number has to be total.
	total=number;
	
	while(1){
		scanf(" %c",&operation);
		if(operation=='='){
			printf("%d",total);
				return 0;
		}
		else{
			scanf("%d",&fnumber);
			if(operation=='+'){
				total+=fnumber;
			}
			else if(operation=='-'){
				total-=fnumber;
			}
			else if(operation=='*'){
				total*=fnumber;
			}
			else if(operation=='/'){
				if(fnumber==0){
					printf("Cant divide by zero \n");
					return 0;
				}
					total*=fnumber;
			}
			else{
					printf("You have entered wrong operation");
					return 0;
			}
		}
	}
}
	
