#include<stdio.h>

void pattern(int arr[][100],int start,int end,int *val);

int main(){

	int n,val=1,i,j;

	scanf("%d",&n);

	int arr[n][100];

	pattern(arr,0,n-1,&val);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}
		
}

void pattern(int arr[][100],int start,int end,int *val){

	int i;

	if(start>end)
		return;
	else if(start==end){
		arr[start][end]=*val;
		return;
	}

	for(i=start;i<=end-1;i++){
		arr[start][i]=*val;
		*val=*val+1;
	}
	for(i=start;i<=end-1;i++){
		arr[i][end]=*val;
		*val=*val+1;
	}
	for(i=end;i>=start+1;i--){
		arr[end][i]=*val;
		*val=*val+1;
	}
	for(i=end;i>=start+1;i--){
		arr[i][start]=*val;
		*val=*val+1;
	}

	pattern(arr,start+1,end-1,val);	
}