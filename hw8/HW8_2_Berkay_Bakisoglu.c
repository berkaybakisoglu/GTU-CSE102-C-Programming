#include <stdio.h>
#include <stdlib.h>
int N=5; // global to create 2D array,it will change depends on file.
int createpath(char* maze);
int findpath(char *maze,char way[][N],int x,int y);
void printway(char way[N][N]);
int main(){
	char* maze;
	char c;
	int i=0,line=0;
	int fsize;
	FILE *fp;
	fp=fopen("maze.txt","r");
	if(fp==NULL){
		printf("Error on file");
		return 0;
	}
	fseek(fp,0,SEEK_END);
	fsize=ftell(fp);
	rewind(fp);
	maze=(char*)malloc(fsize);
	while ((c=fgetc(fp))!=EOF)
    {
		if(c!=' ')
			maze[i++]=c;
		if(c=='\n')
			line++;
    }
	N=line;
	createpath(maze);
	free(maze);
	fclose(fp);
	return 0;
}
int createpath(char *maze){
	int i,j,m=0,n=0,x=0,y=0;
	char way[N][N];
	char maze2[(N*N)];
	
		for(i=0;i<N;++i){
			for(j=0;j<N;++j){
				way[i][j]='0';
			}
		}
			for(m=0;maze[m]!='\0';++m){ //Clear spaces
				if(maze[m]!='\n'){
				maze2[n]=maze[m];
				++n;}
			}
			if(findpath(maze2,way,x,y)==0){ //If it has no solution
				printf("No way out");
				return 0;
			}
			else{
				for(i=0;way[i][j]!='\0';++i){
					for(j=0;way[i][j]!='\0';++j){
						if(way[i][j]=='1')
							way[i][j]='*';
					}
				}
				m=0;
				for(i=0;i<N;++i){
					for(j=0;j<N;++j){
						if(way[i][j]!=maze2[m] && way[i][j]!='*'){
							way[i][j]=maze2[m];
					}
						++m;
				}
			}
				printway(way);
			}
	
	return 0;
}
int findpath(char *maze,char way[][N],int x,int y){
    if(x==N-1 && y==N-1){
        way[x][y]='1';
        return 1;
    }
     if(x>=0 && x<N && y>=0 && y<N && maze[(N*x)+y]=='1'){
        way[x][y]='1';
      if(findpath(maze,way,x+1,y)==1)
            return 1;
      else if(findpath(maze,way,x,y+1)==1)
            return 1;
      else  
		way[x][y]='0';
    }  
    return 0;
}
void printway(char way[N][N]){
	int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
			printf(" %c ",way[i][j]);}
            printf("\n");
    }
}
 
