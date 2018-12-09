#include<stdio.h>

int main(){

char sen[100],word1[20],word2[20],newsen[100];
int i,j,k,t=0,l=0,l1=0,l2=0;

printf("Enter the sentence:");
scanf("%[^\n]",sen);
printf("Enter the word:");
scanf(" %[^\n]",word1);
printf("Enter the word for replacement:");
scanf(" %[^\n]",word2);

while(sen[l]!='\0')
l++;
while(word1[l1]!='\0')
l1++;
while(word2[l2]!='\0')
l2++;

for(i=0;i<l;i++){

k=i;

for(j=0;j<l1;j++){

if(sen[k]==word1[j])
k++;

else
break;

}

k=0;

if(j==l1 && (sen[i+l1]==' ' || sen[i+l1]=='\0') && (sen[i-1]==' ' || i==0)){
while(k<l2)
newsen[t++]=word2[k++];
i=i+l1-1;
}

else
newsen[t++]=sen[i];

}

newsen[t]='\0';

printf("\n%s\n",newsen);

return 0;

}