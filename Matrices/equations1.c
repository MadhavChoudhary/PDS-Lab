#include<stdio.h>

void emergency(float a[101][100],int n);
int shift(float a[101][100],int j,int n);

int main(){

printf("\n-->Equation Solver\n\n");

int i,j,k,n;
float factor;

printf("Enter the number of variables/equations.\n");
scanf("%d",&n);

float a[101][100];

printf("Enter the coeficients in proper order.\n");

for(i=0;i<n;i++){
printf("Enter the numbers of eq%d\n",i+1);
for(j=0;j<=n;j++)
scanf("%f",&a[j][i]);
}

for(j=0;j<n;j++){

if(a[j][j]==0){

if(j==n-1){
emergency(a,n);
return 0;}

else{
i=shift(a,j,n);            //upper triangle form construction
if(i==-1)
continue;
}
}

for(k=j+1;k<n;k++){
factor=a[j][k]/a[j][j];
for(i=0;i<=n;i++)
a[i][k]-=factor*a[i][j];
}
}

for(j=0;j<n;j++)
for(k=j+1;k<n;k++){
if(a[k][k]==0)
continue;
factor=a[k][j]/a[k][k];              //reduced row echelon form
for(i=k;i<=n;i++)
a[i][j]-=factor*a[i][k];
}

for(i=0;i<n;i++){
if(a[i][i]==0)
a[n][i]=0;
else
a[n][i]/=a[i][i];
printf("Solution var%d = %.2f\n",i+1,a[n][i]);
}

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

for(i=0;i<=n;i++){

temp=a[i][j];
a[i][j]=a[i][k];
a[i][k]=temp;

}

}

void emergency(float a[101][100],int n){

int i;

if(a[n][n-1]==0)
printf("These equations have infinite solutions.\n");

else
printf("These equations have no solution.\n");

}





