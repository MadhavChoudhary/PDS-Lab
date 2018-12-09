#include<stdio.h>
#include<math.h>

int main(){

	int n,i,key,res;
	scanf("%d",&n);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("Enter key:");
	scanf("%d",&key);
	printf("Enter the method:");
	scanf("%d",&i);

	switch(i){

		case 1:res=bsearch1(arr,n,key);break;
		case 2:res=bsearch2(arr,n,key);break;
		case 3:res=bsearch3(arr,n,key);break;
		case 4:res=bsearch4(arr,n,key);break;
		case 5:res=bsearch5(arr,n,key);break;
		case 6:res=bsearch6(arr,n,key);break;
		case 7:res=bsearch7(arr,n,key);break;
			
	}

	printf("%d\n",res);
	return 0;
}

//sorted array
int bsearch1(int arr[],int n,int key){

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
}

//floor value
int bsearch2(int arr[],int n,int key){

	int start=0,end=n-1,mid=(start+end)/2;

	while(start<=end){

		if(arr[mid]<key && arr[mid+1]>key)
			return mid;
		else if(arr[mid]>key)
			end=mid-1;
		else
			start=mid+1;

		mid=(start+end)/2;
	}

}

//rotated array
int bsearch3(int arr[],int n,int key){

	int start=0,end=n-1,mid=(start+end)/2;

	while(start<=end){

		if(arr[mid]>arr[mid+1])
			return mid+1;

		else if(arr[end]>arr[mid])
			end=mid-1;

		else
			start=mid+1;

		mid=start+(end-start)/2;
	}

	return -1;
	
}

//frequency of key
int bsearch4(int arr[],int n,int key){

	int start=0,end=n-1,mid=(start+end)/2,pos1,pos2;

	while(start<=end){

		if(key==arr[mid] && arr[mid-1]<key)
			break;

		else if(key==arr[mid] || key<arr[mid])
			end=mid-1;

		else
			start=mid+1;

		mid=(start+end)/2;
	}

	pos1=mid;printf("%d ",pos1);

	start=0;end=n-1;mid=(start+end)/2;

	while(start<=end){

		if(key==arr[mid] && arr[mid+1]>key)
			break;

		else if(key==arr[mid] || key>arr[mid])
			start=mid+1;

		else
			end=mid-1;

		mid=(start+end)/2;
	}

	pos2=mid;printf("%d\n",pos2);

	return pos2-pos1+1;
}

//geometric progression missing
int bsearch5(int arr[],int n,int key){

	int low=0,high=n-1,mid=(low+high)/2;

	float ratio=pow(arr[n-1]/arr[0],1.0/n);

	while(low<=high){

		if(arr[mid+1]/arr[mid]!=ratio)
			return arr[mid]*ratio;

		else if(arr[mid]/arr[mid-1]!=ratio)
			return arr[mid-1]*ratio;

		else if(arr[mid]==arr[0]*pow(ratio,mid))
			low=mid+1;

		else
			high=mid-1;
	}

	return -1;
}

//exponential search for unbounded arrays
int bsearch6(int arr[],int end,int key){

	int start=0,mid=(start+end)/2;

	while(start<=end){

		if(key>arr[mid])
			start=mid+1;
		else if(key<arr[mid])
			end=mid-1;
		else
			return mid;

		mid=start+(end-start)/2;
	}
}

int expsearch(int arr[],int n,int key){

	int i=0,res;

	if(arr[0]==key)
		return 0;

	while(arr[i]<key)
		i*=2;

	res=bsearch6(arr,i,key);

	return res;
}

//local minima 
int bsearch7(int arr[],int n,int key){

	int start=0,end=n-1,mid=(start+end)/2;

	while(start<=end){

		if(arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid])
			return mid;

		else if(arr[mid]>arr[mid-1])
			end=mid-1;

		else if(arr[mid]>arr[mid+1])
			start=mid+1;

		mid=(start+end)/2;
	}

	return -1;
}