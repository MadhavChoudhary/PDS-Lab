#include<stdio.h>

void give_gap(int list[],int sublist[],int n,int point,int t,int r);

int main(){

	int n,i,t=0;
	int list[100]={0},sublist[100]={0};

	printf("Enter the number of numbers :");
	scanf("%d",&n);

	printf("Enter the list :");
	for(i=0;i<n;i++)
		scanf("%d",&list[i]);

	for(i=0;i<n;i++)
	give_gap(list,sublist,n,i,t);

}

void give_gap(int list[],int sublist[],int n,int point,int t){

	int i,sum=0;

	if(point==n)
		return;

	else{

		sublist[t]=list[point];
		
		if(t==2){

			for(i=0;i<3;i++)
				sum+=sublist[i];

			if(sum==0)
				printf("YES\n");

			printf("\n");
			return;
		}


		for(i=1;i<n-point;i++)
			give_gap(list,sublist,n,point+i,t+1);
		
	}
}