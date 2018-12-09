#include<stdio.h>

int main(){

	int n,i,x,j,result=0;

	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&x);

	i=0;j=n-1;
	while(i<j){

		if(arr[i]+arr[j]<x){
			result+=(j-i);i++;}
		else
			j--;
	}

	printf("%d\n",result);

}