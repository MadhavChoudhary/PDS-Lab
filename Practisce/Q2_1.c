#include<stdio.h>
//check if two array are equal
//order of n2
void delarr(int [],int ,int );

int main(){

	int i,j,n;

	scanf("%d",&n);

	int arr1[n],arr2[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr1[i]);

	for(i=0;i<n;i++)
		scanf("%d",&arr2[i]);

	for(i=0;i<n;i++){

		for(j=0;j<n;j++){

			if(arr1[i]==arr2[j]){
				delarr(arr2,j,n);
				break;
			}

		}

	if(j==n){
		printf("No\n");
		return 0;
	}

	}

	printf("Yes\n");

}

void delarr(int arr2[],int j,int n){

	int i;
	for(i=j;i<n-1;i++)
		arr2[i]=arr2[i+1];
}