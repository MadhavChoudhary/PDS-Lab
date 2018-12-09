#include<stdio.h>
//observation that even number of numbers will 
//end up for zero and odd with xor of alternate numbers
int main(){

	int n,i;

	scanf("%d",&n);

	if(n%2==0){
		printf("0\n");
		return 0;}

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int res=arr[1];

	for(i=3;i<n;i+=2)
		res=res^arr[i];

	printf("%d\n",res);
	return 0;

}