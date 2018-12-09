#include<stdio.h>

void sort(int [],int [2][61],int );
int bsearch(int ,int ,int [2][61],int );

int main(){

	int t,i,j,len,start,end,index;
	
	int arr[70][131];
	int n[70];

	scanf("%d",&t);

	for(i=0;i<t;i++){

		scanf("%d",&n[i]);
		for(j=0;j<n[i];j++)
			scanf("%d",&arr[i][j]);
	}

	printf("!!!!!!!!!!!!\n");

	for(i=0;i<t;i++){

		int hash[61]={0};
		int newhash[2][61]={0};
		int newarr[131]={0};

		for(j=0;j<n[i];j++)
			hash[arr[i][j]]+=1;
	printf("!!!!!!!!!!!!\n");
		sort(hash,newhash,61);
	printf("!!!!!!!!!!!!\n");

		while(newhash[0][len]!=0)
			len++;


		for(j=0;j<n[i];j++){

			start=0;
			end=len-1;

			index=bsearch(start,end,newhash,hash[arr[i][j]]);
			
			if(newhash[1][index]==0)
				newhash[1][index]=arr[i][j];
			else{
			 while(newhash[1][index]!=0)
					index++;
				newhash[1][index]=arr[i][j];}

			printf("%d\n",index);
		}

	printf("!!!!!!!!!!!!\n");

		for(j=0;j<len;j++)
			printf("%d ",newhash[0][j]);
		printf("\n");
		for(j=0;j<len;j++)
			printf("%d ",newhash[1][j]);


		for(j=0;j<len;j+=newhash[1][j])
			newarr[j]=newhash[1][j];
		j=0;
		while(j<n[i])
			if(newarr[j]==0)
				newarr[j]=newarr[j-1];
	printf("!!!!!!!!!!!!\n");
		for(j=0;j<n[i];j++)
			printf("%d ",newarr[j]);
	}

}

int bsearch(int first,int last,int newhash[2][61],int k){

	int middle=(first+last)/2;

	while(first<last){

	   if(newhash[0][middle]<k)
	   last=middle;
	                                                              //performing binary search as the data is already newhash[0]
	   else if(newhash[0][middle]>k)
	   first=middle+1;                                                //complexity of search - logn

	   else
	   break;

	   middle=(first+last)/2;
	   

	}

	return middle;
}

void sort(int a[],int newhash[2][61],int n){

int k,t=0,sub;
int arr[2*n];

for(k=n;k<=2*n-1;k++)
arr[k]=a[k-n];

for(k=2*n-2;k>0;k=k-2){

if(arr[k]>arr[k+1])
arr[k/2]=arr[k];

else
arr[k/2]=arr[k+1];

}

sub=0;

while(t<n){

newhash[0][t++]=arr[1];

for(k=2;k<2*n-1;k*=2){

if(arr[k]>arr[k+1])
arr[k]=sub;

else{
arr[k+1]=sub;
k+=1;}

}

for(k=2*n-2;k>0;k=k-2){

if(arr[k]>arr[k+1])
arr[k/2]=arr[k];

else
arr[k/2]=arr[k+1];

}

}

}