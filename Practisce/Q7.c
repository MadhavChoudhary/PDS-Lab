#include<stdio.h>
//longest consecutive subsequence
int LCS(int list[],int n,int rank[],int max[]);

int main(){

	int n,i;

	printf("Enter the size of list.\n");
	scanf("%d",&n);

	int list[100],rank[100]={0},max[2]={0};

	printf("Enter the list.\n");
	for(i=0;i<n;i++)
		scanf("%d",&list[i]);

	LCS(list,n-1,rank,max);

	i=list[max[1]]-max[0]+1;
	printf("\n");
	while(i<=list[max[1]])
		printf("%d ",i++);
 	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",rank[i]);
	
}

int LCS(int list[],int n,int rank[],int max[]){

	int i;

	if(n==0)
		rank[n]=1;

	else if(rank[n]==0){

		rank[n]=1;
		for(i=0;i<n;i++){

			rank[i]=LCS(list,i,rank,max);
			
			if(list[n]==list[i]+1)
				if(rank[n]<rank[i]+1)
					rank[n]=rank[i]+1;
		}
	
		if(max[0]<rank[n]){
			max[0]=rank[n];
			max[1]=n;
		}
	}

	return rank[n];
}