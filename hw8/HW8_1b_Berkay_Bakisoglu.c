#include <stdio.h>
int func(int x,int y);
int main(){
	int x,y;
	printf("Please enter x and y: ");
	scanf("%d %d",&x,&y);
	printf("%d",func(x,y));
	
}
int func(int x,int y){
	if(x>0 && y>0){
		return func(x-1,y)+func(x,y-1)+x+y;
	}
	return 0;
}
