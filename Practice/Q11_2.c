#include<stdio.h>
//order - n
int main(){

	int n,i,j;

	printf("Enter the size of the array\n");
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int sum=0,partsum=0;

	for(i=0;i<n;i++)
		sum+=arr[i];

	for(i=0;i<n;i++){

		partsum+=arr[i];

		if(partsum==sum-partsum)
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