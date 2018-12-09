#include<stdio.h>

int shift(float a[101][100],int j,int n);

int main(){

printf("\n-->Inverse Calculator\n\n");

int i,j,k,n;
float factor;

printf("Enter the number of rows in matrix.\n");
scanf("%d",&n);

float a[101][100]={0};

for(j=0;j<n;j++){
printf("Details of row%d\n",j+1);
for(i=0;i<n;i++)
scanf("%f",&a[i][j]);
}

for(j=0;j<n;j++)
a[j+n][j]=1;

for(j=0;j<n;j++){

if(a[j][j]==0){

if(j==n-1){
printf("No Inverse-singular Matrix.\n");
return 0;}

else{
i=shift(a,j,n);           //upper triangle form construction
if(i==-1){
printf("No Inverse.\n");
return 0;}
}
}

for(k=j+1;k<n;k++){
factor=a[j][k]/a[j][j];
for(i=0;i<2*n;i++)
a[i][k]-=factor*a[i][j];
}
}

for(j=0;j<n;j++)
for(k=j+1;k<n;k++){
factor=a[k][j]/a[k][k];              //reduced row echelon form
for(i=k;i<2*n;i++)
a[i][j]-=factor*a[i][k];
}

for(j=0;j<n;j++)
for(i=n;i<2*n;i++)
a[i][j]/=a[j][j];

printf("Inverse is = \n");

for(i=0;i<n;i++){
for(j=0;j<n;j++)
printf("%.2f ",a[j+n][i]);
printf("\n");
}

return 0;

}

int shift(float a[101][100],int j,int n){

int i,k;
float temp;

for(i=j+1;i<n;i++){
if(a[j][i]!=0)
break;}

if(i!=n)                    //shifting to get non-zero pivot
k=i;
else
return -1;

for(i=0;i<2*n;i++){

temp=a[i][j];
a[i][j]=a[i][k];
a[i][k]=temp;

}

return 0;

}
