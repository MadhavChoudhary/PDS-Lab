#include<stdio.h>

int count=0;
int shift(float a[101][100],int j,int n);

int main(){

printf("\n-->Determinant Finder\n\n");

int i,j,k,n;
float deter=1,factor;

printf("Enter the number of rows of the square matrix.\n");
scanf("%d",&n);

float a[101][100];

printf("Enter the numbers in proper order.\n");

for(i=0;i<n;i++){
printf("Enter the numbers of row%d\n",i+1);
for(j=0;j<n;j++)
scanf("%f",&a[j][i]);
}

printf("Determinant=");

for(j=0;j<n;j++){

if(a[j][j]==0){

if(j==n-1){
printf("0\n");
return 0;}

else{
i=shift(a,j,n);            //upper triangle form construction
if(i==-1){
	printf("0\n");
    return 0;}
}
}

for(k=j+1;k<n;k++){
factor=a[j][k]/a[j][j];
for(i=0;i<n;i++)
a[i][k]-=factor*a[i][j];
}
}

for(i=0;i<n;i++)
deter=deter*a[i][i];

if(count%2==0)
printf("%.2f\n",deter);
else
printf("%.2f\n",-deter);

return 0;

}

int shift(float a[101][100],int j,int n){

int i,k;
float temp;

for(i=j+1;i<n;i++)
if(a[j][i]!=0)
break;

if(i!=n)                    //shifting to get non-zero pivot
k=i;
else
return -1;

count++;

for(i=0;i<=n;i++){

temp=a[i][j];
a[i][j]=a[i][k];
a[i][k]=temp;

}

}