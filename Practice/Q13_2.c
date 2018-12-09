#include<stdio.h>
//order - n
int main(){

	int i,j,n,sum=0,partsum;

	printf("Enter the size\n");
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++){
		partsum=(arr[i]*(i+1)+10*partsum);
		sum+=partsum;
	}

}