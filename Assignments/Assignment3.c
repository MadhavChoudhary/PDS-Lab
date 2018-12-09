#include<stdio.h>

void pattern1(int arr[][100],int start,int end,int *val);
void pattern2(int arr[][100],int start,int end,int n);

	void Q1();
	void Q2();
	void Q3();
	void Q4();
	void Q5();
	void Q6();
	void Q7();
	void Q8();
	void Q9();
	void Q10();
	void Q11();
	void Q12();
	void Q13();
	void Q14();

int main(){

	int ch;
	char ask;

	while(1){

		printf("Enter the question nunber.\n");
		scanf("%d",&ch);

		switch(ch){

			case 1:Q1();break;
			case 2:Q2();break;
			case 3:Q3();break;
			case 4:Q4();break;
			case 5:Q5();break;
			case 6:Q6();break;
			case 7:Q7();break;
			case 8:Q8();break;
			case 9:Q9();break;
			case 10:Q10();break;
			case 11:Q11();break;
			case 12:Q12();break;
			case 13:Q13();break;
			case 14:Q14();break;
			default: return 0;break;

		}

		printf("Do you want to enter other question?\n");
		scanf(" %c",&ask);
		if(ask=='n'||ask=='N')
			break;
	}
}

void Q1(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=count++;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q2(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=i;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[j][i]);
		printf("\n");
	}

}

void Q3(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=i;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q4(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=(i+1)*n-j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q5(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=(n-i-1)*n+j+1;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q6(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=(n-i)*n-j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q7(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=i*n+j+1;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[j][i]);
		printf("\n");
	}

}

void Q8(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1;

	for(i=0;i<n;i++){

		if(i%2==0)
		for(j=0;j<n;j++)
			arr[i][j]=count++;

		else
			for(j=n-1;j>=0;j--)
			arr[i][j]=count++;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q9(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1;

	for(i=0;i<n;i++){

		if(i%2==0)
		for(j=0;j<n;j++)
			arr[i][j]=count++;

		else
			for(j=n-1;j>=0;j--)
			arr[i][j]=count++;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[j][i]);
		printf("\n");
	}

}

void Q10(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1;

	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			arr[i][j]=count++;

	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			arr[i][j]=count++;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q11(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1;

	for(i=0;i<n;i++){

		for(j=i;j<n;j++)
			arr[i][j]=count++;
		for(j=0;j<i;j++)
			arr[i][j]=count++;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q12(){

	int n,i,j;
	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][n];
	int count=1,temp;

	for(i=0;i<n;i++){

		temp=i;j=0;
		while(i>=0)
			arr[i--][j++]=count++;
		i=temp;
	}

	for(j=1;j<n;j++){

		temp=j;i=n-1;
		while(j<n)
			arr[i--][j++]=count++;
		j=temp;
	}


	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d",arr[i][j]);
		printf("\n");
	}

}

void Q13(){

	int n,i,j;

	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][100];

	pattern2(arr,0,n-1,n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}

}

void Q14(){

	int n,i,j,val=1;

	printf("Enter the array size.\n");
	scanf("%d",&n);

	int arr[n][100];

	pattern1(arr,0,n-1,&val);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}

}

void pattern1(int arr[][100],int start,int end,int *val){

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

	pattern1(arr,start+1,end-1,val);	
}

void pattern2(int arr[][100],int start,int end,int n){

	int i;

	if(start==n/2){
		arr[start][end]=(n/2+1)-start;
		return;
	}

	for(i=start;i<=end-1;i++)
		arr[start][i]=(n/2+1)-start;

	for(i=start;i<=end-1;i++)
		arr[i][end]=(n/2+1)-start;

	for(i=end;i>=start+1;i--)
		arr[end][i]=(n/2+1)-start;

	for(i=end;i>=start+1;i--)
		arr[i][start]=(n/2+1)-start;

	pattern2(arr,start+1,end-1,n);	
}
