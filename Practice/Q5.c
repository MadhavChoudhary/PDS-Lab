#include<stdio.h>
//some falthu question don't know what is so difficult in it
int main(){

	int n,k,i,j;

	printf("Enter the number of subtracks.\n");
	scanf("%d",&n);
	printf("Enter the petrol units.\n");
	scanf("%d",&k);

	int track[n];j=k;

	printf("Enter the lenght of subtracks.\n");
	for(i=0;i<n;i++)
		scanf("%d",&track[i]);

	for(i=0;i<n;i++)
		if(track[i]>k)
			k=track[i];

	printf("%d\n",k-j);

	return 0;
}