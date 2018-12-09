#include<stdio.h>

float det(float matrix[100][100],int n);

int main(){
printf("\n-->Determinant Finder\n\n");
int i,j,n;

printf("Enter the size of the square matrix.\n");
scanf("%d",&n);

float matrix[100][100];

for(i=0;i<n;i++){
printf("Enter the numbers of row%d\n",i+1);
for(j=0;j<n;j++)
scanf("%f",&matrix[j][i]);
}

printf("\ndeterminant=%.3f\n",det(matrix,n));

}

float det(float matrix[100][100],int n){

int i,j,k;
float sum=0,submatrix[100][100];

if(n==1)
sum=matrix[0][0];

else{

for(i=0;i<n;i++){

for(j=1;j<n;j++){

for(k=0;k<i;k++)
submatrix[k][j-1]=matrix[k][j];

for(k=i+1;k<n;k++)
submatrix[k-1][j-1]=matrix[k][j];

}


if(i%2==0)
sum+=matrix[i][0]*det(submatrix,n-1);

else
sum-=matrix[i][0]*det(submatrix,n-1);

}

}

return sum;

}
