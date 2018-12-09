#include<stdio.h>

int main(){

	int n,i,key,index;
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	scanf("%d",&key);

	index=bsearch(0,n-1,arr,key);
	printf("%d\n",index);
	return 0;

}

int bsearch(int first,int last,int newhash[],int k){

	int middle=(first+last)/2;

	while(first<last){

	   if(newhash[middle]<k)
	   last=middle;
	                                                              //performing binary search as the data is already newhash[0]
	   else if(newhash[middle]>k)
	   first=middle+1;                                                //complexity of search - logn

	   else
	   break;

	   middle=(first+last)/2;
	   

	}

	return middle;
}