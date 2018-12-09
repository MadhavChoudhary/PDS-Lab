#include<stdio.h>

void mergesort(int [],int ,int ,int );
void merge(int [],int ,int ,int ,int );

int main(){

	int n,i;

	printf("Enter the size of list.\n");
	scanf("%d",&n);

	int arr[n];

	printf("Enter the list.\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	mergesort(arr,0,n-1,n);

	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

}

void mergesort(int arr[],int start,int end,int size){

	if(start>=end)
		return;

	int middle=(start+end)/2;

	mergesort(arr,start,middle,size);
	mergesort(arr,middle+1,end,size);

	merge(arr,start,middle,end,size);
}

void merge(int arr[],int start,int middle,int end,int n){

	int size1,size2;
	int i=0,j=0,k=0;

	size1=middle-start+1;
	size2=end-middle;

	int a1[size1],a2[size2];

	for(i=0;i<size1;i++)
		a1[i]=arr[start+i];
	for(i=0;i<size2;i++)
		a2[i]=arr[middle+1+i];
	i=0;k=start;

	while(i<size1 && j<size2){

		if(a1[i]<a2[j])
		arr[k++]=a1[i++];

		else
		arr[k++]=a2[j++];
	}

	if(i>=size1)
		while(j<size2)
			arr[k++]=a2[j++];

	else if(j>=size2)
		while(i<size1)
			arr[k++]=a1[i++];

}