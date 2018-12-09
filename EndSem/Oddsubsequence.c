#include<stdio.h>

void subsequence(int arr[],int subarr[],int n,int point,int index,int lim,int *max);

int main(){
	
	int n,i,j,index=0,max=-1;
	scanf("%d",&n);
	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int subarr[n];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			subsequence(arr,subarr,n,i,index,j,&max);

	printf("%d\n",max);
}

void subsequence(int arr[],int subarr[],int n,int point,int index,int lim,int *max){

	int gap=1,i,sum=0;

	subarr[index]=arr[point];
	index++;

	if(index==lim){

		for(i=0;i<index;i++)
			sum+=subarr[i];
		if(sum%2!=0 && sum>*max)
			*max=sum;
		return;
	}

	for(gap=1;gap<n-point;gap++)
		subsequence(arr,subarr,n,point+gap,index,lim,max);
}