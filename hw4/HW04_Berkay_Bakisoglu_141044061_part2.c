//Berkay Bakýþoðlu 141044061 homework 4 part 2
#include <stdio.h>
#include <string.h>
#define Max_N 8
#define Max_M 8
int find (char Puzzle[][Max_N],int row , int column ,char orientation,char *word);
int main(){
	int result,row,column;
	char ctrl='y',orientation=' ';
	char word[50];
 	char MyPuzzle[3][Max_N]={{'I','N','E','U','E','L','G','L'},
	 						{'T','L','E','M','O','N','E','O'},
							{'S','C','H','E','R','R','Y','T'}};
	while(ctrl=='y' || ctrl=='Y'){
	printf("Please enter row location : ");
	scanf("%d",&row);
	printf("Please enter column location : ");
	scanf("%d",&column);
	printf("Please enter a orientation : ");
	scanf(" %c",&orientation);
	printf("Please enter a word : ");
	scanf("%s",word);
	if(row<0 || column <0 || word==NULL){
	printf("You have entered wrong instruction");
		return 0;
	}
	result=find(MyPuzzle,row,column,orientation,word);
	printf("%d\n",result);
	printf("Do you want to continue ?\ny/n \n");
	scanf(" %c",&ctrl);}
		return 0;
}
int find (char Puzzle[][Max_N],int row , int column ,char orientation,char* word){
	int i,j,k,m,len_word=0,find=0;
	/*if its not case sensitive.
		for(i=0;word[i]!='\0';i++){
			if(word[i]>='a' && word[i]<='z')
			word[i]=word[i]-32;		
		}
		*/
	for(i=0;word[i]!='\0';++i);
	len_word=i;
	if(len_word==0)	
		return 0;
	if(orientation=='R' ||orientation=='r' ){
		if(len_word>Max_N)
			return 0;
		for(i=row;i<Max_M;++i){
			for(j=column;j<Max_N;++j){
				if(Puzzle[i][j]==word[0]){
					for(k=j+1,m=1;m<len_word && k<Max_N;k++,m++){
						if(Puzzle[i][k]!=word[m]){
							find=0;
							break;
						}
						find=1;
					}
				}
			}
			if(find==1)
				break;		
	}
}
	else if(orientation=='L' || orientation=='l'){
			
		if(len_word>Max_N)
			return 0;
		for(i=row;i<Max_M;++i){
			for(j=column;j>=0;--j){
				if(Puzzle[i][j]==word[0]){
					for(k=j-1,m=1;m<len_word && k>=0;k--,m++){
					if(Puzzle[i][k]!=word[m]){
							find=0;
							break;
						}
						find=1;
					}
				}
			}	
			if(find==1){
				break;
			}	
	}
}
	else if(orientation=='t' || orientation=='T'){
		if(len_word>3)
			return 0;
			for(i=row;i<Max_M;++i){
			for(j=column;j<Max_N;++j){
				if(Puzzle[i][j]==word[0]){
					for(k=i+1,m=1;m<len_word && row<3;k++,m++){
						if(Puzzle[k][j]!=word[m]){
							find=0;
							break;
						}
						find=1;
					}
				}
			}
			if(find==1){
				break;
			}	
	}
	}
	else if(orientation=='B' || orientation=='b'){
		if(len_word>3)
			return 0;
		for(i=row;i<Max_M;++i){
			for(j=column;j<Max_N;j++){
				if(Puzzle[i][j]==word[0]){
					for(k=i-1,m=1;m<len_word && row<3;k--,m++){
						
						if(Puzzle[k][j]!=word[m]){
							find=0;
							break;
						}
						find=1;
					}
				}
			}	
			if(find==1){
				break;
			}
			
	}
}
return find;
}
