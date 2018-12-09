#include<stdio.h>
#include<string.h>

int main(){

	int numb[100],num,temp;
	int sum=0,i,j,subsum=0;
	scanf("%d",&num);
	
	for(i=0;num%10!=0;num/=10)
		numb[i++]=num%10;

	int lim=i%2==0?i/2-1:i/2;

	for(j=0;j<=lim;j++){
		temp=numb[j];
		numb[j]=numb[i-j-1];
		numb[i-j-1]=temp;}

	for(j=0;j<i;j++){
		subsum=(subsum)*10+(j+1)*numb[j];
		sum+=subsum;
	}

	printf("%d\n",sum);
	return 0;
}