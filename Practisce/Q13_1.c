#include<stdio.h>
//order - n2
int main(){

	int i,j,n,sum=0,temp=0;

	printf("Enter the size\n");
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++){
		
		temp=0;
		for(j=i;j<n;j++){

			temp+=arr[j];
			sum+=temp;
			temp*=10;
		}

	}

	printf("%d\n",sum);
	return 0;
}