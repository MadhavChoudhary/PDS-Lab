#include<stdio.h>
//print sublist of size 4 that gives a particular sum
//order - yet to be calculated
void give_gap(int list[],int sublist[],int n,int point,int t,int r);

int main(){

	int n,i,t=0,r;
	int list[100]={0},sublist[100]={0};

	printf("Enter the number of numbers :");
	scanf("%d",&n);
	
	printf("Enter the sum for subset :");
	scanf("%d",&r);

	printf("Enter the list :");
	for(i=0;i<n;i++)
		scanf("%d",&list[i]);

	for(i=0;i<n;i++)
	give_gap(list,sublist,n,i,t,r);

}

void give_gap(int list[],int sublist[],int n,int point,int t,int r){

	int i,sum=0;
		
		if(t==3){

			for(i=0;i<4;i++)
				sum+=sublist[i];

			if(sum==r)
				for(i=0;i<4;i++)
					printf("%d ",sublist[i]);

			printf("\n");
			return;
		}

		for(i=1;i<n-point;i++)
			give_gap(list,sublist,n,point+i,t+1,r);
		
}