#include<stdio.h>
//largest number by joining numbers of an array
void sort(int a[],int sorted[],int n);

int main(){

	int i,j,k,max,temp,term,unit,n;
	printf("Enter n:");
	scanf("%d",&n);

	int list[n],sorted[n],size[n][3];

	for(i=0;i<n;i++)
	scanf("%d",&list[i]);

	for(i=0;i<n;i++)
	{
		temp=list[i];
		k=0;

		while(temp!=0)
		{
			temp/=10;
			k++;
		}
		
		size[i][0]=k;
		size[i][1]=list[i];

	}

	max=size[0][0];

	for(i=1;i<n;i++)
	if(size[i][0]>max)
	max=size[i][0];

	for(i=0;i<n;i++)
	{
		temp=list[i]%10;
		term=0;
		unit=1;

		for(j=size[i][0];j<max;j++)
		{
			term+=temp*unit;
			unit*=10;
		}

		temp=list[i];

		for(j=0;j<size[i][0];j++)
		{
			term+=(temp%10)*unit;
			temp/=10;
			unit*=10;
		}

		list[i]=term;
		size[i][2]=list[i];
	}

	sort(list,sorted,n);

	for(i=0;i<n;i++)
	{
		temp=sorted[i];

		for(j=0;j<n;j++)
		{
			if(size[j][2]==temp)
				break;
		}

		sorted[i]=size[j][1];
	}

	for(i=0;i<n;i++)
	printf("%d",sorted[i]);

	printf("\n");
	return 0;
}

void sort(int a[],int sorted[],int n)
{

	int k,t=0,sub;
	int arr[2*n-1];

	for(k=n;k<=2*n-1;k++)
		arr[k]=a[k-n];

	for(k=2*n-2;k>0;k=k-2)
	{

		if(arr[k]>arr[k+1])
			arr[k/2]=arr[k];

		else
			arr[k/2]=arr[k+1];

	}

	sub=minimum(a,n,0)-1;

	while(t<n)
	{

		sorted[t++]=arr[1];

		for(k=2;k<2*n-1;k*=2)
		{

			if(arr[k]>arr[k+1])
				arr[k]=sub;

			else
			{
				arr[k+1]=sub;
				k+=1;
			}

		}

		for(k=2*n-2;k>0;k=k-2)
		{

			if(arr[k]>arr[k+1])
				arr[k/2]=arr[k];

			else
				arr[k/2]=arr[k+1];

		}

	}

}

int minimum(int arr[],int n,int k){

int min,j;

if(arr[k]>arr[k+1])
		min=arr[k+1];

else
	min=arr[k];

for(j=k+2;j<n-1;j+=2)
{

	if(arr[j]>arr[j+1])
	{
		if(arr[j+1]<min)
		min=arr[j+1];
	}

	else if(arr[j]<min)
		min=arr[j];

}

return min;

}