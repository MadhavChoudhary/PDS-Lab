#include<stdio.h>

float det(float matrix[100][100],int n);
void sub(float submatrix[100][100],float matrix[100][100],int i,int j,int n);

int main(){
printf("\n-->Inverse Finder\n\n");
int i,j,n;

printf("Enter the size of the square matrix.\n");
scanf("%d",&n);

float matrix[100][100],cofmatrix[100][100],deter,submatrix[100][100];

for(i=0;i<n;i++){
printf("Enter the numbers of row%d\n",i+1);
for(j=0;j<n;j++)
scanf("%f",&matrix[j][i]);
}

deter = det(matrix,n);

if(deter==0){
printf("This matix is not invertible\n");
return 0;}

for(i=0;i<n;i++)
	for(j=0;j<n;j++){

		sub(submatrix,matrix,i,j,n);

		if((i+j)%2==0)
		cofmatrix[j][i]=det(submatrix,n-1);

	    else
	    cofmatrix[j][i]=-det(submatrix,n-1);
	
	}

printf("\nInverse is=\n");

for(i=0;i<n;i++){
	for(j=0;j<n;j++)
        printf("%3.2f ",cofmatrix[j][i]/deter);
    printf("\n");
}
   printf("\n");
   return 0;     
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

void sub(float submatrix[100][100],float matrix[100][100],int i,int j,int n){

int t,k;

for(t=0;t<j;t++){

for(k=0;k<i;k++)
submatrix[k][t]=matrix[k][t];

for(k=i+1;k<n;k++)
submatrix[k-1][t]=matrix[k][t];

}

for(t=j+1;t<n;t++){

for(k=0;k<i;k++)
submatrix[k][t-1]=matrix[k][t];

for(k=i+1;k<n;k++)
submatrix[k-1][t-1]=matrix[k][t];
}

}