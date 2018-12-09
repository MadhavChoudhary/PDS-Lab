#include<stdio.h>
//sorting even and odd numbers of an array
//order 2nlogn can be decreased to nlogn + 2n by comparing in heap sort itself
int min(int [],int );
void sort(int [],int );

int main(){

	int n,i,j=0,k=0;

	scanf("%d",&n);

	int arr[n],oddarr[n],evenarr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++){

		if(arr[i]%2!=0)
			oddarr[j++]=arr[i];

		else
			evenarr[k++]=arr[i];
	}

	sort(oddarr,j);
	sort(evenarr,k);

	for(i=0;i<j;i++)
		arr[i]=oddarr[j];
	for(i=j;i<n;i++)
		arr[i]=evenarr[k];

	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

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