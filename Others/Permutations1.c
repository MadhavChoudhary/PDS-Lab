#include<stdio.h>

void permute(char [],int ,int );
void swap(char [],int ,int );
void string_sort(char [],int );

int main(){

	int l;
	char list[100];

	printf("Enter the string\n");
	scanf("%s",list);

	while(list[l]!='\0')
		l++;

	printf("The permutations are:\n");
	string_sort(list,l);
	permute(list,0,l-1);
	
	return 0;
}

void permute(char list[],int start,int end){

	int i;

	if(start==end)
		printf("%s\n",list);
		
	else{
		
		for(i=start;i<=end;i++){

			if(list[start]==list[i] && start!=i)
				continue;
			swap(list,start,i);
			permute(list,start+1,end);
			swap(list,start,i);

		}
	}

	return;
}

void swap(char list[],int x,int y){

	int temp;

	temp=list[x];
	list[x]=list[y];
	list[y]=temp;
}

void string_sort(char list[],int l){

	int i,j;

	for(i=0;i<l;i++)
		for(j=i+1;j<l;j++)
			if(list[i]>list[j])
				swap(list,i,j);

}