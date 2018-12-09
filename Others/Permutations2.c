#include<stdio.h>

void perm(char str[],int l,int len,int r,char store[],char repeat[],int *t);
void delete(char new[],char str[],int i,int len);

int main(){

int l=0,len=0,r,t=0;
char str[100];

printf("Enter the string:");
scanf("%s",str);

printf("How many do you want to combine at a time:");
scanf("%d",&r);

while(str[len]!='\0')
len++;

char store[len+1],repeat[len+1];

perm(str,l,len,r,store,repeat,&t);

}

void perm(char str[],int l,int len,int r,char store[],char repeat[],int *t){

int i;
char new[100];

if(r==0){

store[l]='\0';

for(i=0;i<*t;i++)
if(repeat[i]==store[0])
break;

if(i==*t){
repeat[*t]=store[0];
printf("%s\n",store);
*t++;
}

}

else{

for(i=0;i<len;i++){

store[l]=str[i];
delete(new,str,i,len-1);
perm(new,l+1,len-1,r-1,store,repeat,t);

}

}

}

void delete(char new[],char str[],int i,int len){

int k;

for(k=0;k<i;k++)
new[k]=str[k];

for(k=i;k<len;k++)
new[k]=str[k+1];

}
