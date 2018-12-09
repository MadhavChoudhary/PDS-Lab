#include<stdio.h>
//order - n, my function was-order - n^2 worst case
int main(){

	int n,m,i,j,temp;

	scanf("%d",&n);
	scanf("%d",&m);

	int arr[m][3];

	for(i=0;i<m;i++){

		scanf("%d",&arr[i][0]);
		scanf("%d",&arr[i][1]);
		scanf("%d",&arr[i][2]);
	}

	/*while(1){

		temp=find(arr,m);
		if(temp==m)
			break;
		m=temp;
	}

	temp=0;
	for(i=0;i<n;i++)
		if(arr[i][2]>temp)
			temp=arr[i][2];*/
	temp=bestfind(arr,m);
	printf("%d\n",temp);

	return 0;
}

/*int find(int arr[][3],int m){

	int i,j=0,t;

	for(i=1;i<m;i++){

		if(arr[i][0]>arr[j][1] || arr[i][1]<arr[j][0])
			j=i;

		else{
			
			arr[j][0]=arr[j][0]>arr[i][0]?arr[j][0]:arr[i][0];
			arr[j][1]=arr[j][1]>arr[i][1]?arr[i][1]:arr[j][1];
			arr[j][2]=arr[j][2]+arr[i][2];

			for(t=0;t<3;t++)
				arr[i][t]=0;
		}
	}

	j=-1;
	//removal of duplicates
	for(i=0;i<m;i++){

		if(arr[i][2]==0 && arr[i-1][2]!=0)
			j=i;
		else if(j!=-1)
			for(t=0;t<3;t++){
				arr[j][t]=arr[i][t];arr[i][t]=0;
			}

	}

	i=0;
	while(arr[i][2]!=0)
		i++;

	return i;
		
}*/

int bestfind(int arr[][3],int m){

	int hash[1000],sum=0,max=0,i;

	for(i=0;i<m;i++){

		hash[arr[i][0]]+=arr[i][2];
		hash[arr[i][1]+1]-=arr[i][2];
	}

	for(i=0;i<m;i++){

		sum+=hash[i];
		if(sum>max)
			max=sum;
	}

	return max;
}