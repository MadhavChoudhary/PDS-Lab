#include<stdio.h>

void mergesort(int [],int ,int ,int );
void merge(int [],int ,int ,int ,int );
int bsearch(int [],int ,int );

int main(){

	int n1,n2,i,j,pos=0,x,t;

    scanf("%d",&t);
	
    for(j=0;j<t;j++){

	    scanf("%d",&n1);
		scanf("%d",&n2);
		scanf("%d",&x);
		int arr2[n2];
		int arr1[n1];
    
    	for(i=0;i<n1;i++)
    		scanf("%d",&arr1[i]);
    
    	for(i=0;i<n2;i++)
    		scanf("%d",&arr2[i]);
    
    	if(n2>n1){
    
    		mergesort(arr1,0,n1-1,n1);
    
    		for(i=0;i<n2;i++){
    
    			pos=bsearch(arr1,n1,x-arr2[i]);
    			
    			if(pos!=-1)
    				printf("%d %d ",arr1[pos],arr2[i]);
    		}
    	}
    
    	else{
    
    		mergesort(arr2,0,n2-1,n2);
    
    		for(i=0;i<n1;i++){
    
    			pos=bsearch(arr2,n2,x-arr1[i]);
    			if(pos!=-1)
    				printf("%d %d\n",arr1[i],arr2[pos]);
    		}
    	}
    }

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

int bsearch(int arr[],int n,int key){

	int start=0,end=n-1,mid=(start+end)/2;

	while(start<=end){

		if(key>arr[mid])
			start=mid+1;
		else if(key<arr[mid])
			end=mid-1;
		else
			return mid;

		mid=start+(end-start)/2;
	}

	return -1;
}