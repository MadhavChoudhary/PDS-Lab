#include<stdio.h>

void Q1();
void Q2();
void Q3();
void Q4();

int main(){

int x;

while(1){

printf("Enter the question you want:");
scanf("%d",&x);

switch (x){

case 1:Q1();break;
case 2:Q2();break;
case 3:Q3();break;
case 4:Q4();break;
default:printf("Enter a proper question no.\n");break;

}

}
return 0;
}

void Q1(){
printf("-->Palindrome checker\n");
char str[100];
int i=0,j;

printf("Enter the word:");
scanf("%s",str);

while(str[i]!='\0')
i++;

for(j=0;j<i/2;j++)
if(str[j]!=str[i-j-1])
break;

if(j==i/2)
printf("This is a palindrome.\n");

else
printf("This is not a palindrome.\n");

}

void Q2(){
printf("-->First occurence of substring\n");
char word[1000],comp[1000];
int k,j,i,l1=0,l2=0;

printf("Enter a word\n");
scanf("%s",word);
printf("Enter another smaller word\n");
scanf("%s",comp);

while(word[l1]!='\0')
l1++;
while(comp[l2]!='\0')
l2++;

for(i=0;i<l1;i++){
j=i;
for(k=0;k<l2;k++){

if(word[j]==comp[k])
j++;

else
break;

}

if(k==l2){
printf("Index=%d\n",i);
break;}

}

if(i==l1)
printf("-1\n");

}

void Q3(){
printf("-->Can be formed by simple rotation?\n");
char str1[100],str2[100];
int x=0,y=0,i,t=0,len;

printf("Enter first string:");
scanf("%s",str1);

printf("Enter second string:");
scanf("%s",str2);

while(str1[x]!='\0')             
x++;

while(str2[y]!='\0')
y++;

if(x!=y){
printf("-1\n");
return;}

len=x;

for(i=0;i<len;i++)
if(str1[0]==str2[i])
break;

while(t<len){

if(i==len)
i=0;                                                                   //optimised code

if(str1[t++]!=str2[i++]){
printf("-1\n");
return;}

}

printf("1\n");

}

void Q4(){
printf("-->Reverse the sentence\n"); 
getchar();

char sen1[100],sen2[100];
int len=0,k=0,t=0,i=0,j;
int word[20];

printf("Enter your sentence:");
scanf("%[^\n]",sen1);

while(sen1[len]!='\0')
len++;

for(i=0;i<len;i++)
if(sen1[i]==' ')
word[k++]=i;

if(k>0){

for(j=word[k-1]+1;j<len;j++)
sen2[t++]=sen1[j];

sen2[t++]=' ';

for(i=2;i<=k;i++){

for(j=word[k-i]+1;j<word[k-i+1];j++)
sen2[t++]=sen1[j];

sen2[t++]=' ';

}

for(j=0;j<word[0];j++)
sen2[t++]=sen1[j];

}

else
for(j=0;j<len;j++)
sen2[t++]=sen1[j];

sen2[t]='\0';
printf("%s\n",sen2);

}
