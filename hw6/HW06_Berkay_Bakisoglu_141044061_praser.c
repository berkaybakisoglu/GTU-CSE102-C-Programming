// I cant find a way to print emails as pdf wants,so i tried most readable
//If you can share code after duedate i will be pleasured.
#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2000 //to allocate char arrays
int nmail=0;
int errorcheck(char* mails);
int main(){
FILE* tp;
FILE* fp;
char mails[MAX_SIZE]="";
char backup[MAX_SIZE]="";
char keywords[MAX_SIZE]="";
char c_line[100]="";
char filename[50]="emails.txt"; //filenames
char filename1[50]="token.txt";
char* pmails;
int i,k,j,c,msize,tsize,error=0,line,ntoken,count,temp,str,number;
char ret[250];
char *i1;
char *i2;
size_t p1,mlen;
fp=fopen("emails.txt","r");
tp=fopen("token.txt","r");
if(fp==NULL || tp==NULL)
	return 0;
//Find size of mails	
fseek(fp,0,SEEK_END);
msize=ftell(fp); 
rewind(fp);
//Find size of tokens
fseek(tp,0,SEEK_END);
tsize=ftell(tp);
rewind(tp);
//reads tokens
      while(fgets(c_line,sizeof c_line,tp)!=NULL)
      {
        strcat(keywords,c_line);
      }
//Error check
line=1;
for(i=0;i<=tsize;++i){
	if(keywords[i]=='='){ 
		for(k=i+2;keywords[k]!='\n' && keywords[k]!='\0';++k){
			i=k;
			if(!(keywords[k]>='0' && keywords[k]<='9')){
				error=1;
				i=tsize;
			}
		}
	}
	if(keywords[i]=='\n')
		line++;
}
if(error==1){
	printf("ERROR in token.txt's line %d \n",line);}
else{
	//print tokens	
for(i=0;keywords[i]!='\0';++i){
	if(keywords[i]=='\n'){
		ntoken++;
	}
}
ntoken+=1;
printf("Token file %s.Total tokens read: %d \n",filename1,ntoken);
printf("--------------------------------------------------------------\n");
printf("| # | token                              |    Frequency      |\n");
printf("--------------------------------------------------------------\n");
 k=0;
for(i=1;i<=ntoken &&keywords[k+2]!='.';++i){
	count=0;
	printf("| %d |",i);
	for(k;keywords[k]!='=';++k){
		count++;
		printf("%c",keywords[k]);
	}
	++k;
	for(count;count<=35;++count)
	printf(" ");
		printf("|");
	for(count;count<=50;++count)
		printf(" ");
	printf(" |");
	for(k;keywords[k]!='\n' && keywords[k]!='\0';++k){
		printf("%c",keywords[k]);
	}
	++k;
	printf("|");
	
	printf("\n");
}
}
printf("\n");
	//Reads mail
	 fread(mails,msize,sizeof(char),fp);
	 //check errors on mail
	if(errorcheck(mails)==0)
		printf("****There is an error in mails format****\n");
	else{
		printf("--------------------------------------------------------------\n");
		printf("Email file %s.Total mails read: %d\n\n",filename,nmail);
strcpy(backup,mails);
for(i=1;i<=nmail;++i){
	for(number=0;number<i-1;number++){ //jump mail
	i1 = strstr(mails+i,"</email>");
	strcpy(mails,i1);
}
	strcpy(ret,"");
	//Seperates subject
	i1 = strstr(mails,"<Subject>");
    p1 = strlen("<Subject>");
    i2 = strstr(i1 + p1, "</Subject>");
    mlen = i2 - (i1 + p1);
    memcpy(ret, i1 + p1, mlen);
    ret[mlen] = '\0';
	printf("%d.Subject |",i);
	printf("%s |\n",ret);
	//Seperates Body
	i1 = strstr(mails,"<Body>");
    p1 = strlen("<Body>");
    i2 = strstr(i1 + p1, "</Body>");
    mlen = i2 - (i1 + p1);
    memcpy(ret,i1 +p1,mlen);
    ret[mlen]='\0';
	printf("Body: ");
	printf("%s \n\n",ret);
	strcpy(ret,"");
	strcpy(mails,backup);
}
}
}
int errorcheck(char *mails){
	int i,j,c;
	int e1=0,e2=0,s1=0,s2=0,b1=0,b2=0 ;// counts
char *sm="<email>";
char *em="</email>";
char *ss="<Subject>";
char *es="</Subject>";
char *sb="<Body>";
char *eb="</Body>";
	i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==sm[0]){
			for(j=0;j<strlen(sm);++j){
				if(mails[i+j]!=sm[j]){
					j=strlen(sm)+2;
				}
			}
			if(j==strlen(sm)){
				e1++;
			}
		}
		++i;
	}
	i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==em[0]){
			for(j=0;j<strlen(em);++j){
				if(mails[i+j]!=em[j]){
					j=strlen(em)+2;
				}
			}
			if(j==strlen(em)){
				e2++;
			}
		}
		++i;
	}
		i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==ss[0]){
			for(j=0;j<strlen(ss);++j){
				if(mails[i+j]!=ss[j]){
					j=strlen(ss)+2;
				}
			}
			if(j==strlen(ss)){
				s1++;
			}
		}
		++i;
	}
		i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==es[0]){
			for(j=0;j<strlen(es);++j){
				if(mails[i+j]!=es[j]){
					j=strlen(es)+2;
				}
			}
			if(j==strlen(es)){
				s2++;
			}
		}
		++i;
	}
		i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==sb[0]){
			for(j=0;j<strlen(sb);++j){
				if(mails[i+j]!=sb[j]){
					j=strlen(sb)+2;
				}
			}
			if(j==strlen(sb)){
				b1++;
			}
		}
		++i;
	}
		i=j=0;
	while(i<strlen(mails)){
		if(mails[i]==eb[0]){
			for(j=0;j<strlen(eb);++j){
				if(mails[i+j]!=eb[j]){
					j=strlen(eb)+2;
				}
			}
			if(j==strlen(eb)){
				b2++;
			}
		}
		++i;
	}
	if(e1<e2)
		nmail=e1;
	else
		nmail=e2;
	if(b1==b2 && e1==e2 && s1==s2)
		return 1;
	return 0;
}
