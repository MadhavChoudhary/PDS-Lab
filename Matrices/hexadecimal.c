#include<stdio.h>

int main(){

int i,j,k=0,n;
char str[100];
int arr[100],redirect[100];

printf("Enter the number:");
scanf("%d",&n);

while(n>0){

if(n%16>=10){

i=n%16;
str[k]=i-10+'A';
n=n/16;
redirect[k]=0;
k++;

}

else{

arr[k]=n%16;
n=n/16;
redirect[k]=1;
k++;

}

}

for(j=k-1;j>=0;j--){

if(redirect[j]==0)
printf("%c",str[j]);
else
printf("%d",arr[j]);

}

printf("\n");

}
