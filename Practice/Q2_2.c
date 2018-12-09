#include<stdio.h>
//check if two arrays are equal
//order nlogn
int min(int [],int );
void sort(int [],int );

int main(){

	int n,i,j,k;

	scanf("%d",&n);

	int arr1[n],arr2[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr1[i]);

	for(i=0;i<n;i++)
		scanf("%d",&arr2[i]);

	sort(arr1,n);
	sort(arr2,n);

	for(i=0;i<n;i++)
		if(arr1[i]!=arr2[i])
			return 0;

	printf("Yes");
	return 0;

}

void sort(int a[],int n){

	int i,low,k=n;

	int arr[2*n];

	for(i=n;i<2*n;i++)
		arr[i]=a[i-n];

	for(k=2*n-2;k>0;k-=2){

		if(arr[k]>arr[k+1])
			arr[k/2]=arr[k];
		else
			arr[k/2]=arr[k+1];
	}

	low=min(a,n);

	for(i=0;i<n;i++){

		a[i]=arr[1];
		arr[1]=low;

		for(k=2;k<2*n;k/=2){

			if(arr[k]>arr[k+1])
				arr[k]=low;

			else{

				arr[k+1]=low;
				k=k+1;
			}
		}

		for(k=2*n-2;k>0;k-=2){

			if(arr[k]>arr[k+1])
				arr[k/2]=arr[k];
			else
				arr[k/2]=arr[k+1];
		}

	}


}

int min(int arr[],int n){

	int min=arr[0],i;

	for(i=1;i<n;i++)
		if(arr[i]<min)
			min=arr[i];

	return min;
}