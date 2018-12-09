#include<stdio.h>
#include<string.h>
#define MAX_SIZE 50

void permute(char str[],int l,int start);
void swap(char str[],int x,int y);


void Q1();
void Q2();
void Q3();
void Q4();
void Q5();
void Q6();
void Q7();

int main(){

int q;


while(1){
printf("Enter the question no.\n");
scanf("%d",&q);

switch(q){
case 1:Q1();break;
case 2:Q2();break;
case 3:Q3();break;
case 4:Q4();break;
case 5:Q5();break;
case 6:Q6();break;
case 7:Q7();break;
}

}

}

void Q1(){

int i,j,n;

printf("Enter the number of words\n");
scanf("%d",&n);

char words[n][100],len[n];

for(i=0;i<n;i++){

printf("Enter %d word",i+1);
scanf("%s",words[i]);

}

int max_len=0;

for(i=0;i<n;i++){

len[i]=strlen(words[i]);
if(len[i]>max_len)
max_len=len[i];

}

int row=n+4,col=max_len+4;
char arr[row][col];

printf("%d",max_len);
for(j=0;j<col;j++){
arr[0][j]='*';arr[1][j]=' ';
arr[row-1][j]='*';arr[row-2][j]=' ';
}

for(i=1;i<row-1;i++){
arr[i][0]='*';arr[i][1]=' ';
arr[i][col-1]='*';arr[i][col-2]=' ';
}

for(i=2;i<row-1;i++){

for(j=2;j<len[i-2]+2;j++)
arr[i][j]=words[i-2][j-2];

for(j=len[i-2]+2;j<col-1;j++)
arr[i][j]=' ';

}

printf("\n");
for(i=0;i<row;i++){
for(j=0;j<col;j++)
printf("%c",arr[i][j]);
printf("\n");
}

}

void Q3(){

int i,j,n;

printf("Enter the array size\n");
scanf("%d",&n);

int arr[n],max=0,temp;

printf("Enter the array.\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
if(arr[i]>max)
max=arr[i];
}

temp=max;

for(i=0;i<max;i++){

for(j=0;j<n;j++){

if(arr[j]>=temp){
printf("#");
}

else
printf(" ");

}

temp--;
printf("\n");

}

}




void Q5(){

int n,len1,len2,t=0,flag;
char s[100],x[100];

printf("Enter s:\n");
scanf("%s",s);

printf("Enter x:\n");
scanf("%s",x);

len1=strlen(s);
len2=strlen(x);

flag=check(s,x,len1,len2,t);

if(flag==1)
printf("%s-ish\n",x);

else
printf("Not %s-ish\n",x);


}

int check(char s[],char x[],int len1,int len2,int t){

int i;
if(t==len2)
return 1;

for(i=0;i<len1;i++)
if(s[i]==x[t])
return check(s,x,len1,len2,t+1);



}


void Q4(){

int size,i,j;
int array[MAX_SIZE][MAX_SIZE];
printf("Enter the size (<%d) of the square matrix: ",MAX_SIZE);
scanf("%d",&size);

//part a
for(i=0;i<size;i++){
for(j=0;j<i;j++)
array[i][j]=(i+1)*size-i+j+1;
for(j=i;j<size;j++)
array[i][j]=i*size+j+1-i;

}

for(i=0;i<size;i++){
for(j=0;j<size;j++){
printf("%5d ",array[i][j]);}
printf("\n");
}

//part b
for(i=0;i<size;i++)
for(j=0;j<size;j++)
array[i][j]=(i+1)*size-j;

for(i=0;i<size;i++){
for(j=0;j<size;j++){
printf("%5d ",array[i][j]);}
printf("\n");
}

}


void Q6(){

int i,j,k,temp,dega,degb;

printf("Enter the degree of the first polynomial.\n");
scanf("%d",&dega);
printf("Enter the degree of the second polynomial.\n");
scanf("%d",&degb);


int a[dega+1],b[degb+1],q[dega-degb],r[degb];

printf("Enter the coefficients of first polynomial.\n");
for(i=0;i<=dega;i++)
scanf("%d",&a[i]);

printf("Enter the coefficients of second polynomial.\n");
for(i=0;i<=degb;i++)
scanf("%d",&b[i]);

for(i=0;i<=dega-degb;i++){

j=0;
temp=a[i]/b[j];
k=i;
q[i]=temp;
for(j=0;j<=degb;j++,k++)
a[k]-=temp*b[j];

}


k=0;
while(i<=dega){
r[k]=a[i];i++;k++;}


printf("Quotient\n");
for(i=0;i<dega-degb+1;i++)
printf("%d ",q[i]);
printf("\n");

printf("REmainder\n");
for(i=0;i<degb;i++)
printf("%d ",r[i]);
printf("\n");
}


void Q2(){

/*int i,j,k,n,key,index;

printf("Enter the size of the array.\n");
scanf("%d",&n);

printf("Enter the key.\n");
scanf("%d",&key);

int arr[n];

printf("Enter the elements.\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);

int start=0,middle,end=n-1;
middle=(start+end)/2;

while(start<end-1){

if(newarr[middle]<key)
start=middle;

else if(newarr[middle]>key)
end=middle;

else
break;

middle=(start+end)/2;

}


k=n-index;

int t=0;
int newarr[n];

for(i=index;i<n;i++)
newarr[t++]=arr[i];
for(i=0;i<index;i++)
newarr[t++]=arr[i];

for(i=0;i<n;i++)
	printf("%d",newarr[i]);

printf("%d",key);

start=0,middle,end=n-1;

middle=(start+end)/2;

while(start<end-1){

if(newarr[middle]<key)
start=middle;

else if(newarr[middle]>key)
end=middle;

else
break;

middle=(start+end)/2;

}

if(start==end-1)
printf("-1\n");

else if(middle-k>0)
printf("Index=%d\n",middle);
else
printf("Index=%d\n",n-middle+1);

*/}

void Q7(){

char str[100];
int l,i,j,start=1;

printf("Enter the string.\n");
scanf("%s",str);

l=strlen(str);

printf("\n");

permute(str,l,0);

printf("\n");

for(i=l-1;i>=start;i--){
for(j=i-1;j>=start;j--)
if(str[j]<str[i]){
swap(str,i,j);
rev(str,i+1,j-1);
break;}
if(j!=start-1)
break;
}


printf("%s\n",str);

}

void permute(char str[],int l,int start){

int i;

if(start==l){
printf("%s\n",str);
return;
}

for(i=start;i<l;i++){

swap(str,start,i);
permute(str,l,start+1);
swap(str,start,i);

}

}

void swap(char str[],int x,int y){

int temp;

temp=str[x];
str[x]=str[y];
str[y]=temp;

}

void rev(char str[],int x,int y){
 int i,j;
	for(i=x,j=y;i<=j;i++,j--)
		swap(str,i,j);
}



 
/*void swap(char *a,char *b)
{
 if( *a == *b )
  return;
*a^=*b;
 *b^=*a;
*a^=*b;
}
void rev(string& s,int l,int r)
{
 while(l<r)
 swap(&s[l++],&s[r--]);
}
 
int bsearch (string& s,int l,int r,int key)
{
    int index = -1;
    while(l<=r)
    {
int mid = l+(r-l)/2;
if(s[mid]<=key)
r=mid-1;
else
{
            l=mid+1;
if(index = -1 || s[index]<=s[mid])
                index = mid;
}
}
return index;
}
 
bool nextpermutation(string& s)
{
int len = s.length(), i=len-2;
while(i>=0 && s[i]>=s[i+1])
 --i;
if(i<0)
return false;
else
{
int index=bsearch(s,i+1,len-1,s[i]);
swap(&s[i],&s[index]);
rev(s,i+1,len-1);
return true;
    }
}

*/








































































