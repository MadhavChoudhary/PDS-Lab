#include<stdio.h>
//order - n2
int main(){

	int n,i,j;

	printf("Enter the size of the array\n");
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int sum1=0,sum2=0;

	for(i=0;i<n;i++){

		for(j=0;j<i;j++)
			sum1+=arr[j];
		for(j=i;j<n;j++)
			sum2+=arr[j];

		if(sum1==sum2)
			break;
	}

	if(i!=n){
		for(j=0;j<=i;j++)
			printf("%d ",arr[j]);
		printf("\n");
		for(j=i+1;j<n;j++)
			printf("%d",arr[j]);
		printf("\n");
	}

	else
		printf("Not Possible\n");

	return 0;

}