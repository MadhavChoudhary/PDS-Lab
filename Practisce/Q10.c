#include<stdio.h>
//good question
//order - n 
int main(){

	int arr[]={13, 10, 14, 9, 17, 21, 16, 18, 13, 17},n,i;

	printf("Enter the size n.\n");
	scanf("%d",&n);

	int a[n];

	int temp=arr[n-1]-arr[1];

	a[1]=(temp+arr[0])/2;
	a[0]=arr[0]-a[1];

	for(i=2;i<n;i++)
		a[i]=arr[i-1]-a[0];

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	return 0;
}