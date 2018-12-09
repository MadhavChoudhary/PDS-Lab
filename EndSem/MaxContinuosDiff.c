#include<stdio.h>

int main(){

	int n,res=0,i,j,itemp=-1,jtemp=-1;
	scanf("%d",&n);
	int arr[n];
	int hash[100]={0};
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	for(i=0;i<n;i++)
		hash[arr[i]]++;

	i=0;j=99;

	while(hash[j]==0)
		j--;
	jtemp=j;
	j--;

	while(i<j){

		if(hash[i]==0)
			i++;
		else if(jtemp!=-1){
			res+=(jtemp-i);itemp=i;i++;
		}

		if(hash[j]==0)
			j--;
		else if(itemp!=-1){
			res+=(j-itemp);jtemp=j;j--;
		}


	}

	i=0;
	while(hash[i]==0)
		i++;
	res+=(jtemp-i);
	
	printf("%d\n",res);
	return 0;

}