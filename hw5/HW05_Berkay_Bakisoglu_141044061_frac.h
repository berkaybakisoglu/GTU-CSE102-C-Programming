#ifndef SFRAC_H_  
#define SFRAC_H_

char r[100];
char* sfrac_simplify(char * n);
char * sfrac_add(char * n1, char * n2);
char * sfrac_sub(char * n1, char * n2);
char * sfrac_negate(char * n);
char * sfrac_mult(char * n1, char * n2);
char * sfrac_div(char * n1, char * n2);
char * sfrac_fromdouble(double x);
double sfrac_todouble(char * x);
void sfrac_print(char *a1, char *n1, char *a2, char *n2, char *a3, char *n3, char *a4);
int lcm(int i1,int i2);
int gcd(int i1,int i2);
#endif
