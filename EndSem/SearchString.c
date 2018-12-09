#include<stdio.h>

int isempty(char str[]){

	if(str[0]=='\0')
		return 0;
	else return 1;
}

int main(){

	int i,n;
	char key[1000];
	char arr[100][1000];

	scanf("%d",&n);

	for(i=0;i<n;i++)
	scanf("%s",arr[i]);

	scanf("%s",key);


//bsearch

	int first=0;int last=n-1;int left,right;
	int middle=(first+last)/2;

	while(first<last){

		if(isempty(arr[middle]))
			do{left=middle-1;right=middle+1;}
			while(isempty(arr[left]) && isempty(arr[right]));

		else if(key[0]>arr[middle][0])
			first=middle;
		else if(key[0]<arr[middle][0])
			last=middle;
		else
			break;

		middle=(first+last)/2;

	}

	printf("The positon is %d\n",middle);
	return 0;

}


