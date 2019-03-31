//Berkay Bakýþoðlu 141044061 homework 4 part 1
#include <stdio.h>
void init(int S[][9]);
int is_legal (int S[][9] , int r, int c, int x);
void read_from_file (FILE *file_pointer, int S[][9]);
void place(int S[][9],int r,int c,int x);
void write_to_file(FILE*file_pointer,int S[][9]);
int main(){
	FILE* fp=fopen("sudoku.txt","r");
	FILE *ofp=fopen("output.txt","a+");
	if (fp==NULL)
		return 0;
	int array[9][9];
	int i,j;
	init(array);
	read_from_file(fp,array);
	write_to_file(ofp,array);
	return 0;
}
void init(int S[][9]){
	int i,j;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			S[i][j]=0;
		}
	}
}
void read_from_file (FILE *file_pointer, int S[][9]){
int i,j,x,ctrl=1;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			fscanf(file_pointer,"%d",&x);
		if(is_legal(S,i,j,x)==1)
			place(S,i,j,x);
		else {
			printf("Error on row %d column %d ",i,j);
			ctrl=0;
		}
		}
		
	}
	if(ctrl==1){
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			printf("%d ",S[i][j]);
		}
		printf("\n");
	}
}

}
int is_legal (int S[][9] , int r, int c, int x){
	int i,j,k,m,ctrl=1,ctrl2=1,ctrl3=1,b_r,b_c;
	b_r=(r/3)*3;//3x3
	b_c=(c/3)*3;//3x3
	for(i=0;i<9;++i){ // checks rows
		if(i!=r){
		if(S[i][c]==x){
			if(x!=0){
				ctrl=0;
		
		}
	}
	}
	}
	for(j=0;j<9;++j){ // checks columns
		if(j!=c){
		if(S[r][j]==x){
			if(x!=0)
				ctrl2=0;
		}
	}
	}
	for(k=0;k<3;k++) // checks 3x3 part
		for(m=0;m<3;m++){
			if(S[b_r+k][b_c+m]==x)
				if(x!=0)
					ctrl3=0;
		}
	if(ctrl==1 && ctrl2==1 &&ctrl3==1)
		return 1;
	else return 0;
}
void place(int S[][9],int r,int c,int x){
	S[r][c]=x;
}
void write_to_file(FILE*file_pointer,int S[][9]){
	int i,j;
	fprintf(file_pointer,"Write to file >> \n");
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
	fprintf(file_pointer,"%d ",S[i][j]);
}
fprintf(file_pointer,"\n");
}
}
