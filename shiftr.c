#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
int main()
   {
      puts("GRAMMAR is S->A^B \n B->b \n A->a*c \n A->a+c \n b->c-d");
      puts("enter input string ");
      scanf("%s",a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      puts("stack \t input \t action");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='a' || a[j]=='b' || a[j]=='c')
           {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%s%c",stk,a,act,stk[i]);
              check();
           }
         else
           {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
              check();
           }
       }
   
 if(stk[0]=='S' && stk[1]=='\0')
      printf("\n\n Valid\n");
else
   printf ("\n\n Invalid!!!!!\n");
    }
void check()
   {
     
     for(z=0; z<c; z++)
       if(stk[z]=='b' )
         { if(z==0)
              strcpy(ac,"REDUCE TO B");
           stk[z]='B';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           j++;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='a' && stk[z+1]=='*' && stk[z+2]=='c')
         { if(z==0)
              strcpy(ac,"REDUCE TO A");
           stk[z]='A';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='a' && stk[z+1]=='+' && stk[z+2]=='c')
         { if(z==0)
              strcpy(ac,"REDUCE TO A");
           stk[z]='A';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='c' && stk[z+1]=='-' && stk[z+2]=='d')
         { 
           if(z==0)
              strcpy(ac,"REDUCE TO B");
           stk[z]='B';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='A' && stk[z+1]=='^' && stk[z+2]=='B')
         { if(z==0)
              strcpy(ac,"REDUCE TO S");
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
   }
