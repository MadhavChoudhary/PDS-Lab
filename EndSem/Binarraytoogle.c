#include<stdio.h>

int main(){

	int n,i,count=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	if(arr[0]==1){
		count++;arr[0]=0;
	}

	for(i=1;i<n-1;i++){

		if(arr[i-1]+arr[i+1]==2 && arr[i]==0){
			count++;arr[i]=1;}

		else if(arr[i-1]+arr[i+1]==0 && arr[i]==1){
			count++;arr[i]=0;}

	}

	if(arr[i-1]==1 && arr[i]==0)
		count++;

	printf("%d\n",count);
	return 0;
}