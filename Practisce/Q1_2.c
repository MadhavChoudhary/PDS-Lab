#include<stdio.h>
//largest number by joing the elements of an array
//order n2, can be decreased by doing the same in toursort
int main(){

	int n,i,j,temp;

	scanf("%d",&n);

	int list[n];

	for(i=0;i<n;i++)
		scanf("%d",&list[i]);

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){

			if(comp(list[i],list[j])){

				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}

		}


	for(i=0;i<n;i++)
		printf("%d",list[i]);

	printf("\n");
}

int comp(int x,int y){

int unit1,unit2,i=x,j=y;

for(unit1=1;i>0;i/=10)
	unit1*=10;

for(unit2=1;j>0;j/=10)
	unit2*=10;

printf("\n");
	if((x+unit1*y)>(y+unit2*x))
		return 1;

	else 
		return 0;

}