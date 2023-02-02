#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
     struct  proc
    {
        char *c;
        int x,y;
        
    } ;
     char *token;
int n,metN,period;
char pt[20] ,c2[20];
scanf("%s",pt);
printf("\n  the printing way :%s",pt);
scanf("%d",&metN);
printf("\n the method :%d",metN);

scanf("%d",&period);    /* code */

printf("\n the period %d",period);
scanf("%d",&n);    /* code */

printf(" \n the no of processes :%d",n);
struct proc proc1[n];
scanf("%s",c2);
char s[2] = ",";
token = strtok(c2, s);
printf("\n");
char in[n][n];
for (int i = 0; i < n; i++)
{

 proc1[i].c= (char*) malloc(20*sizeof(char));



// while( token != NULL ) {
     printf( " name :%s\n", token );
     strcpy(in[i],token);
    proc1[i].c=in[i];
      token = strtok(NULL, s);
           printf( " %s\n", token );

    proc1[i].x= atoi (token);
     token = strtok(NULL, s);
      printf( " %s\n", token );
    proc1[i].y= atoi (token);
//    }
if(i != (n-1)) {
   scanf("%s",c2);
 token = strtok(c2, s);
 }else {
 
    break;}
    
}
printf("\n out of loop");
for (int i = 0; i < n; i++)
{

  printf(" \n process no %d name : %s ",i , proc1[i].c);
//  printf(" \n process no %d name : %s ",i , in[i]);
   printf(" \n process no %d arrive : %d ", i,proc1[i].x);
    printf(" \n process no %d brust : %d",i , proc1[i].y);
}

}