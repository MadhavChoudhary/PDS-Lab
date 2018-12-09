#include<stdio.h>

void Q1();
void Q2();
void Q3();
void Q4();
void Q5();
void Q6();
void sort(int [],int [],int );
int minimum(int [],int ,int );

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
case 5:Q5();break;
case 6:Q6();break;
default:printf("Enter a proper question no.\n");break;

}

}
return 0;
}

void Q1(){
printf("-->Max and Second Max\n");
int n,k,max,smax,temp,min;

printf("Enter n:");
scanf("%d",&n);

int arr[2*n];

for(k=n;k<=2*n-1;k++)
scanf("%d",&arr[k]);

min=minimum(arr,2*n,n);

for(k=2*n-2;k>0;k=k-2){

if(arr[k]>arr[k+1])
arr[k/2]=arr[k];
                                                                 //tree data structure
else                                                             // complexity - N for finding max
arr[k/2]=arr[k+1];

}

max=arr[1];
smax=min;

for(k=2;k<2*n-1;k*=2){

if(arr[k]>arr[k+1]){
if(arr[k+1]>smax)                                                // complexity - logN for finding smax
smax=arr[k+1];
}
else{
if(arr[k]>smax)                                                 
smax=arr[k];
k=k+1;
}

}

printf("max= %d,second max= %d,min= %d\n",max,smax,min);

}

void Q2(){
printf("-->Maximum Sum subsequence\n");
int n,sum,i,k,j,temp,x,y;

printf("Enter n:");
scanf("%d",&n);

int a[n];

for(i=0;i<n;i++)
scanf("%d",&a[i]);

sum=a[0];
                                                                      //taking all continuous sub sequences and updating value of sum
for(i=0;i<n;i++){
for(j=i;j<n;j++){

temp=0;

for(k=i;k<=j;k++)                                                    
temp=temp+a[k];                                                       

if(temp>sum){
sum=temp;
x=i;y=j;
}

}
}

printf("The series is i= %d to j= %d, sum is %d.\n",x,y,sum);

}

void Q3(){
printf("-->Distinct non-repeated integer\n");
int n,i,j,temp=0;

printf("Enter n:");
scanf("%d",&n);

int a[n];

for(i=0;i<n;i++)
scanf("%d",&a[i]);

i=0;

while(i<n){

temp=0;

for(j=i+1;j<n;j++){

if(a[i]==a[j]){
while(j<n-1){                                                 //deleting the similar elements
a[j]=a[j+1];j++;}
n-=1;temp++;break;                                            //rechecking avoided
}

}

if(temp==0){
printf("%d\n",a[i]);
break;}

i++;

}

}

void Q4(){
printf("-->Rotate the list\n");
int n,k,t,i=0,x,y;

printf("Enter n an k:");
scanf("%d %d",&n,&k);

int a[n],b[n];y=k;

for(x=0;x<n;x++)
scanf("%d",&a[x]);

for(t=n-y;t<n;t++)
b[i++]=a[t];

for(t=0;t<n-y;t++)
b[k++]=a[t];

for(x=0;x<n;x++)
printf("%d ",b[x]);

printf("\n");

}

void Q5(){
printf("-->Element repeating more than n/2 times\n"); 
int n,i,j,k,t,temp;

printf("Enter n:");
scanf("%d",&n);

int a[n];temp=n/2;

for(i=0;i<n;i++)
scanf("%d",&a[i]);

for(i=0;i<n;i++){

k=n;

for(j=i+1;j<n;j++){

if(a[i]==a[j]){
t=j;
while(t<n-1){                                                            //deleting all similar elements to avoid recomparision
a[t]=a[t+1];t++;}
n=n-1;j--;                                                               //reduced counting operations to decrease time coimplexity
}

}

if((k-n)>=temp){
printf("%d\n",a[i]);
break;}

}

if(i==n-1)
printf("-1");

}

void Q6(){
printf("-->Rank of element in sorted list\n");
int n,i,j,temp,k;

printf("Enter n:");
scanf("%d",&n);

int a[n],sorted[n];

for(i=0;i<n;i++)
scanf("%d",&a[i]);

k=a[n-1];

sort(a,sorted,n);                                                    //used tournament tree data structure for sorting
                                                                     //complexity - nlogn + n
int first=0,last=n-1,middle=(first+last)/2;

while(first<=last){

   if(sorted[middle]<k)
   last=middle;
                                                              //performing binary search as the data is already sorted
   else if(sorted[middle]>k)
   first=middle+1;                                                //complexity of search - logn

   else{
   i=middle;
   break;}

   middle=(first+last)/2;

}

printf("The rank is %d\n",n-i-1);

}

void sort(int a[],int sorted[],int n){

int k,t=0,sub;
int arr[2*n];

for(k=n;k<=2*n-1;k++)
arr[k]=a[k-n];

for(k=2*n-2;k>0;k=k-2){

if(arr[k]>arr[k+1])
arr[k/2]=arr[k];

else
arr[k/2]=arr[k+1];

}

sub=minimum(a,n,0)-1;

while(t<n){

sorted[t++]=arr[1];

for(k=2;k<2*n-1;k*=2){

if(arr[k]>arr[k+1])
arr[k]=sub;

else{
arr[k+1]=sub;
k+=1;}

}

for(k=2*n-2;k>0;k=k-2){

if(arr[k]>arr[k+1])
arr[k/2]=arr[k];

else
arr[k/2]=arr[k+1];

}

}

}

int minimum(int arr[],int n,int k){

int min,j;

if(arr[k]>arr[k+1])
min=arr[k+1];

else
min=arr[k];

for(j=k+2;j<n-1;j+=2){

if(arr[j]>arr[j+1]){
if(arr[j+1]<min)
min=arr[j+1];}

else
if(arr[j]<min)
min=arr[j];

}

return min;

}


