#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 4000 //to allocate char arrays
int nmail=0;
int errorcheck(char* mails);
int main(){
FILE* tp;
FILE* fp;
char mails[MAX_SIZE]="";
char backup[MAX_SIZE]="";
char keywords[MAX_SIZE]="";
char c_line[200]="";
char filename[50]="emails.txt"; //filenames
char filename1[50]="token.txt";
char token[100]="";
char val[20];
char* pmails;
int i=0,k,j,c,m,n,occur=0,msize,tsize,tc=0,error=0,line,ntoken,count,temp,number,value,spam,len;
char ret[250];
char *i1;
char *i2;
size_t p1,mlen;
fp=fopen("emails.txt","r");
tp=fopen("token.txt","r");
if(fp==NULL || tp==NULL){
	printf("File cannot found");
	return 0;
}
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
    	++i;
        strcat(keywords,c_line);
    }
      
//Error check token
line=1;k=0;
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
k=0;
j=0;
	//Reads mail
	fread(mails,msize,sizeof(char),fp);
	 //check errors on mail
	if(errorcheck(mails)==0){
		printf("****There is an error in mails format****\n");
		return 0;
	}	
for(i=0;keywords[i];i++){
  keywords[i]=tolower(keywords[i]);
}
for(i=0;mails[i];i++){
  mails[i]=tolower(mails[i]);
}
if(error==1){
	printf("ERROR in token.txt's line %d \n",line);}	
	
for(i=0;keywords[i]!='\0';++i){
	if(keywords[i]=='\n'){
		ntoken++;
	}
}
k=0;
c=0;
strcpy(backup,mails);
for(i=1;i<=nmail;++i){
	for(number=0;number<i-1;number++){ //jump mail
		i1 = strstr(mails+i,"</email>");
		strcpy(mails,i1);
}
	strcpy(ret,"");
	i1 = strstr(mails,"<subject>");
    p1 = strlen("<subject>");
    i2 = strstr(i1 + p1, "</body>");
    mlen = i2 - (i1 + p1);
    memcpy(ret, i1 + p1, mlen);
    ret[mlen] = '\0';
for(c=0;c<=tsize;++c){
	if(keywords[c]!='='){
		token[k]=keywords[c];
		k++;}
	else if(keywords[c]=='='){
		len=strlen(token);
		for(m=0;ret[m]!='\0';++m){
			n=0;
			count=0;
			while(ret[m]==token[n]){
				count++;m++;n++;
			}
			if(count==len-1)
				occur++;
		}
		c+=2;

		while(keywords[c]>='0' && keywords[c]<='9'){
			val[j]=keywords[c];
			j++;
			++c;
		}
		value=atoi(val);
		if(value==occur)
			spam=1;
		if(spam==1){
			c=tsize;
			printf("Mail %d is spam. \n",i);
		}
			memset(token,0,100);
		k=0;
		j=0;
		spam=0;
		occur=0;	
	}
}
strcpy(mails,backup);
strcpy(ret,"");
}
}
int errorcheck(char *mails){
	int i,j,c;
	int e1=0,e2=0,s1=0,s2=0,b1=0,b2=0 ;// counts
char *sm="<email>";
char *em="</email>";
char *ss="<subject>";
char *es="</subject>";
char *sb="<body>";
char *eb="</body>";
for(i = 0; mails[i]; i++){
  mails[i] = tolower(mails[i]);
}
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
