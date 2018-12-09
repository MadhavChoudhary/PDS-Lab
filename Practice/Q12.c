#include<stdio.h>
//order - n
int main(){

	int i,j=0,n,x,count=0;

	printf("Enter the size and sum\n");
	scanf("%d %d",&n,&x);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=n-1;i>j;i--)
		if(arr[j]+arr[i]<x){

			count+=(i-j);
			j++;i++;
		}

	printf("%d\n",count);
	return 0;
}