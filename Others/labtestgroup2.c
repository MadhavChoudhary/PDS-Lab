#include<stdio.h>

int cancer(char [],char [], int ,int );

int main(){

int l1=0,l2=0,l=0;
char string[100],substring[100];

printf("Enter the string:");
scanf("%[^\n]",string);
printf("Enter the substring:");
scanf("%s",substring);

while(string[l1]!='\0')
l1++;
while(substring[l2]!='\0')
l2++;

while(1){

l=cancer(string,substring,l1,l2);

if(l==l1)
break;

else
l1=l;

}

printf("\n%s\n",string);

return 0;

}

int cancer(char string[],char substring[], int l1,int l2){

int i,j,k,t;

for(i=0;i<l1;i++){

k=i;

for(j=0;j<l2;j++){

if(string[k]==substring[j])
k++;

else
break;  }

if(j==l2){
while(k<=l1)
string[k-l2]=string[k++];
string[k]='\0';
l1=l1-l2;
i--;
}

}

return l1;

}







