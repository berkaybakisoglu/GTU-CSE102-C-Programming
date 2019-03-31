/*
*********************************************
* Berkay Bakýþoðlu 141044061 homework2 part1*
*
*********************************************
*/
#include <stdio.h>
#include <math.h>
#define PI 3,14
void Draw_Triangle(int starting_point,int length,int layer_type);
void Draw_Rectangle(int starting_point,int length,int width,int layer_type);
void Draw_Circle(int center,int radius,int layer_type);
int main(){
	char shape;
	int sp,length,layert,width,center,radius;
		printf("What do you want to draw?\n");
		printf("a)Triangle \nb)Rectangle \nc)Circle\n");
		scanf("%c",&shape);
		if(shape=='a'|| shape=='A'){
			printf("Please enter a starting point ");
			scanf("%d",&sp);
			printf("Please enter a length ");
			scanf("%d",&length);
			printf("Please enter layer_type ");
			scanf("%d",&layert);
			Draw_Triangle(sp,length,layert);
		}
		else if(shape=='b'||shape=='B'){
			printf("Please enter a starting point ");
			scanf("%d",&sp);
			printf("Please enter a length ");
			scanf("%d",&length);
			printf("Please enter a width ");
			scanf("%d",&width);
			printf("Please enter layer_type ");
			scanf("%d",&layert);
			Draw_Rectangle(sp,length,width,layert);
		}
		else if(shape=='c' || shape=='C'){
			printf("Please enter a center ");
			scanf("%d",&center);
			printf("Please enter a radius ");
			scanf("%d",&radius);
			printf("Please enter layer_type ");
			scanf("%d",&layert);
			Draw_Circle(center,radius,layert);
		}
		else{
			printf("You should have entered a,b or c");
			return 0;
		}
}
void Draw_Triangle(int starting_point,int length,int layer_type){
	int i,j,k,h;
	printf("\n"); //for look better
	if(starting_point>=0 && length>=0){
	if(!(layer_type==1 || layer_type==2)){
		printf("You entered wrong layer type");	
		
	}
	else if(layer_type==1){
		for(i=1;i<=length;++i){
			for(j=0;j<starting_point;++j){
				printf(" ");
			}
			for(h=0;h<length-i;++h)
        {
            printf(" ");
        } 
			while(k!=2*i-1){
				printf("*");
				++k;
			}
			printf("\n");
			k=0;
		}
	}
	else if(layer_type==2){
		for(i=1;i<=length;++i){
			for(j=0;j<starting_point;++j){
				printf(" ");
			}
			for(h=0;h<=length-i;++h)
        {
            printf("  ");
        }
			while(k!=2*i-1){
				printf("**");
				++k;
			}
			printf("\n");
			k=0;
		}
	}
}
else
	printf("Wrong instruction\n");
}
void Draw_Rectangle(int starting_point,int length,int width,int layer_type){
	int i,j,k,m,n,h;
	printf("\n"); //for look better
	if(starting_point>=0 && length>=0 && width>=0){
	if(!(layer_type==1 || layer_type==2)){
		printf("You entered wrong layer type");	
		
	}
	else if(layer_type==2){
		for(i=0;i<length*2;++i){
			for(j=0;j<starting_point;++j){
				printf(" ");
			}
				if(i<2){
				for(m=0;m<width;++m){
					printf("**");
				}
			}
				else if(i>=2 && i<length*2-2){
					printf("**");
					for(n=0;n<width*2-4;++n){
						printf(" ");
					}
					printf("**");
				}
				else if(i>=length*2-2){
					for(h=0;h<width*2;++h){
						printf("*");
					}
				}
			printf("\n");
		}
	}
	else if(layer_type==1){
		for(i=0;i<length;++i){
			for(j=0;j<starting_point;++j){
				printf(" ");
			}
				if(i<1){
				for(m=0;m<width;++m){
					printf("*");
				}
			}
				else if(i>=1 && i<length-1){
					printf("*");
					for(n=0;n<width-2;++n){
						printf(" ");
					}
					printf("*");
				}
				else if(i>=length-1){
					for(h=0;h<width;++h){
						printf("*");
					}
				}
			printf("\n");
		}
	}
}
	else
		printf("Wrong instruction");
}
void Draw_Circle(int center,int radius,int layer_type){
	int y,i;
	int r_out,x,value;
	printf("\n"); //for look better
	if(center>=0 && radius>0){
		if(center>=radius){
			if(layer_type==1){
				r_out=radius;
				y=radius;
				while (y>=-radius){
					for(i=0;i<center-radius;++i){
						printf(" ");
					}
					x=-radius;
				while(x<r_out){
					value = x*x+y*y;
					if(value==(r_out*r_out)){
						printf("*");
				}
					else{
						printf(" ");
						if(y==0&&x==r_out-1){
							printf("*");
					}
				}
					x+=1;
			}
				printf("\n");
				y-=1;
			}
			}
				else if(layer_type==2){
					r_out=radius;
					y=radius;
					while (y>=-radius){
						for(i=0;i<center-radius;++i){
						printf(" ");
						}
					x=-radius;
					while(x<r_out){
						value = x*x+y*y;
						if(value==(r_out*r_out)){
							printf("**");
					}
						else{
							printf(" ");
							if(y==0&&x==r_out-1){
								printf("**");
						}
					}
						x+=1;
				}
					printf("\n");
					y-=1;
				}
			}
		else{
			printf("You have entered wrong layer type");
		}
	}
	else
		printf("Radius cannot bigger than center");
}
	else printf("Wrong instruction");
}



