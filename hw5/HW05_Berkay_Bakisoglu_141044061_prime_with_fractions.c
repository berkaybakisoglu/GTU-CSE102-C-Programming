#include<stdio.h>
#include "sfrac.h"
void prime_with_fractions(){
int i=3,c=1,d,primes[1000];
primes[0]=2;
   while(c<1000)
   {
      for(d=2;d<i;++d)
      {
         if(i%d==0)
            break;
      }
      if(d==i)
      {
      	primes[c]=i;
         ++c;
      }
      ++i;
   }
   for(i=0;i<1000;++i){
   	printf("%d \n",primes[i]);
   }
}
int main(){
prime_with_fractions();
	return 0;
}
