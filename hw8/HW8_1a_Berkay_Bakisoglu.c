#include <stdio.h>
int tobinary(int number);
int main(){
	int number,binary;
	printf("Please enter a number to convert binary: ");
	scanf("%d",&number);
	binary=tobinary(number);
	printf("%d",binary);
	return 0;
}
int tobinary(int number){
	if(number<0){
		number=-number;
}
	if(number!=0){
		return number%2+10*tobinary(number/2);
	}
	return number;
}
