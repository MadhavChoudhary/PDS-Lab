#include<stdio.h>

float det(float matrix[100][100],int n);
void sub(float submatrix[100][100],float matrix[100][100],int i,int n);

int main(){

printf("\n-->Equation Solver\n\n");

int i,j,k,n;
float temp,deter;

printf("Enter the number of variables/equations.\n");
scanf("%d",&n);

float a[101][100],matrix[100][100];

printf("Enter the coeficients in proper order.\n");

for(i=0;i<n;i++){
printf("Enter the details of eq%d\n",i+1);
for(j=0;j<=n;j++)
scanf("%f",&a[j][i]);
}

for(k=0;k<n;k++){

for(j=0;j<n;j++)
for(i=0;i<n;i++)
matrix[i][j]=a[i][j];

for(j=0;j<n;j++)
	matrix[k][j]=a[n][j];

temp=det(matrix,n);
deter=det(a,n);

if(deter!=0)
printf("sol%d = %.2f\n",k+1,temp/deter);

else if(temp==0){
printf("These equations have infinite solutions\n");
break;}

else{
printf("These equations have no solutions\n");
break;}

}

return 0;

}

float det(float matrix[100][100],int n){

int i,j,k;
float sum=0,submatrix[100][100];

if(n==1)
sum=matrix[0][0];

else{

for(i=0;i<n;i++){

sub(submatrix,matrix,i,n);

if(i%2==0)
sum+=matrix[i][0]*det(submatrix,n-1);

else
sum-=matrix[i][0]*det(submatrix,n-1);

}

}

return sum;

}

void sub(float submatrix[100][100],float matrix[100][100],int i,int n){

int j,k;

for(j=1;j<n;j++){

for(k=0;k<i;k++)
submatrix[k][j-1]=matrix[k][j];

for(k=i+1;k<n;k++)
submatrix[k-1][j-1]=matrix[k][j];

}

}