#include<stdio.h>
#include<stdbool.h>
#include<math.h>

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
void Q15();
void Q16();
bool prime(int );
int comb(int ,int );
void binary(int );


int main(){

int x;

while(1){

printf("Enter the question you want:");
scanf("%d",&x);

switch (x){

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
case 15:Q15();break;
case 16:Q16();break;
default:printf("Enter a proper question no.\n");break;

}

}
return 0;
}

void Q1(){
printf("-->Leap Year Checker\n");
int n;

printf("Enter a year:");
scanf("%d",&n);

if(n%100==0)
n/=100;
if(n%4==0)
printf("  The year you entered is leap year.\n");
else
printf("  The year you entered is not leap year.\n");

}

void Q2(){
printf("-->Possible combinations of currency notes\n");
int n,a,b,c;
float k;

printf("Enter the amount:");
scanf("%d",&n);

for(c=0;c<=(n/100);c++)
for(b=0;b<=(n/50);b++){

k=((n-c*100-b*50)/10);
a=k;

if((k-a)==0 && a>=0)
if((a*10+b*50+c*100)==n)
printf("  (%d) 100 rupee notes, (%d) 50 rupee notes, (%d) 10 rupee notes\n",c,b,a);
else
printf("  Not possible to represent in availiable currency.\n");

}

}

void Q3(){
printf("-->Area and Perimeter calculator\n");
float x1,x2,x3,y1,y2,y3,k,a,b,c;

printf("Enter the cordinates:");
scanf("%f %f",&x1,&y1);
printf("Enter the cordinates:");
scanf("%f %f",&x2,&y2);
printf("Enter the cordinates:");
scanf("%f %f",&x3,&y3);
a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
b=sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
c=sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

k= x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);

if(k==0)
printf("  The lines are collinear.\n");

else if(k<0){
printf("  Area = %f\t",-k/2);
printf("  Perimeter = %f\n",a+b+c);}

else{
printf("  Area = %f\t",k/2);
printf("  Perimeter = %f\n",a+b+c);}

}

void Q4(){
printf("-->Input type Finder\n");
int ascii;
char c;

printf("Enter something:");
scanf(" %c",&c);

ascii=c;

if(ascii<=90 && ascii>=65)
printf("  %c is an upper case letter.\n",c);

else if(ascii<=122 && ascii>=97)
printf("  %c is an lower case letter.\n",c);

else if(ascii<=57 && ascii>=48)
printf("  %c is a number.\n",c);

else
printf("  %c is a special symbol.\n",c);

}

void Q5(){
printf("-->Gregorian Calender\n");
int y,x,k,t=0;

printf("Enter the year:");
scanf("%d",&y);

if(y>1900){

for(x=1900;x<y;x++){
k=x;
if(k%100==0)
k=k/100;

if(k%4==0)
t+=2;
else
t+=1;

}

t=t%7;

if(t==0)
printf("  It is monday\n");
else if(t==1)
printf("  It is tuesday\n");
else  if(t==2)
printf("  It is wednesday\n");
else if(t==3)
printf("  It is thursday\n");
else if(t==4)
printf("  It is friday\n");
else if(t==5)
printf("  It is saturday\n");
else
printf("  It is sunday\n");

}

else
printf("  Enter a valid year i.e greater than 1900.\n");

}

void Q6(){
printf("-->Sum of digits\n");
int k,temp,sum=0;

printf("Enter the number:");
scanf("%d",&k);

while(k>0){

temp=k%10;
k=k/10;
sum=temp+sum;

}

printf("  Sum of its digits is = %d\n", sum);

}

void Q7(){
printf("-->Reverse the digits\n");
int k,temp;

printf("Enter the number:");
scanf("%d",&k);
printf("  ");

while(k>0){

temp=k%10;
k=k/10;
printf("%d",temp);

}
printf("\n");
}


void Q8(){
printf("-->Binary Converter\n");
int n;

printf("Enter the number:");
scanf("%d",&n);
printf("  ");

binary(n);

printf(" is the binary form\n");

}

void Q9(){
printf("-->Prime and Prime factor Finder\n");
int n,k;

printf("Enter the number:");
scanf("%d",&n);

if(prime(n))
printf("  It is a prime number\n");

else{

printf("  It is a composite number. Prime factors are:\n");

for(k=2;k<=n;k++){

if(n%k==0){

if(prime(k))
printf("%d ",k);

}

}

}

printf("\n");

}


void Q10(){
printf("-->Amstrong Numbers\n");
int n,k,temp,lim;

printf("Give a limit:");
scanf("%d",&lim);

for(k=1;k<lim;k++){

int sum=0;
n=k;

while(n>0){

temp=n%10;
n=n/10;
sum=sum+(temp*temp*temp);

}

if(sum==k)
printf("  %d is amstrong number\n",k);

}

}

void Q11(){
printf("-->Number Counter\n");
int n,pos=0,neg=0,zer=0;
char ans;

while(1){

printf("Enter your number:");
scanf("%d",&n);

if(n>0)
pos++;

else if(n<0)
neg++;

else
zer++;

getchar();

printf("Do you want to print another number?(y/n)\n");
scanf("%c",&ans);

if(ans == 'y' || ans == 'Y')
continue;

if(ans == 'n' || ans == 'N')
break;

}

printf("  The number of positive numbers =%d, negetive numbrs =%d, zeros =%d\n",pos,neg,zer);

}

void Q12(){
printf("-->Sin(X) Function\n");
float k=1,sin=0;
int temp=0;
float n;

printf("Enter your angle:");
scanf("%f",&n);

n=(n*3.14)/180;

while(1){

temp++;

float fact=1,a,exp=1;

for(a=1;a<=k;a++)
fact=fact*a;

for(a=1;a<=k;a++)
exp=exp*n;


if((exp/fact)<=0.00001)
break;

if(temp%2==0)
sin=sin-(exp/fact);

else
sin=sin+(exp/fact);

k=2*k+1;

}

printf("  sin(0)= %f\n",sin);

}

void Q13(){
printf("-->BiPyramid Pattern\n");
int n,k,t;

printf("Enter the number of rows:");
scanf("%d",&n);

for(k=1;k<=n;k++){

for(t=k;t<n;t++)
printf(" ");

for(t=1;t<=k;t++){
printf("*");
printf(" ");
}

printf("\n");

}

for(k=n-1;k>0;k--){

for(t=k;t<n;t++)
printf(" ");

for(t=1;t<=k;t++){
printf("*");
printf(" ");
}

printf("\n");

}

}

void Q14(){
printf("-->Alphabet Pattern\n");
char ch;
int n,t,k;

printf("Enter an upper case letter:");
scanf(" %c",&ch);

n=ch-'A';

for(k=0;k<=n;k++)
printf("%c",'A'+k);
for(k=n-1;k>=0;k--)
printf("%c",'A'+k);
printf("\n");

for(t=1;t<=n;t++){

for(k=0;k<=n-t;k++)
printf("%c",'A'+k);

for(k=1;k<=2*t-1;k++)
printf(" ");

for(k=n-t;k>=0;k--)
printf("%c",'A'+k);

printf("\n");

}

}

void Q15(){
printf("-->Fibonacci series\n");
int n,fib1=1,k,fib2=1,temp;

printf("Enter the value of n:");
scanf("%d",&n);

if(n>0){
printf("1 ");n--;}

if(n>0){
printf("1 ");n--;}

if(n!=0){

for(k=0;k<n;k++){

temp=fib1+fib2;
fib1=fib2;
fib2=temp;
printf("%d ",temp);

}

}
printf("\n");

}

void Q16(){
	printf("-->Pascal Triangle\n");
	int i,j,k,n;
	
	printf("Enter the number of rows:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		
	    for(k=0;k<n-i;k++)
		    printf(" ");
			
		for(j=0;j<=i;j++){
			
			if(j==0 || j==i)
			printf("%d ",1);
			else
			printf("%d ",comb(i,j)/comb(j,j));
		}
		
		printf("\n");
		
	}
}

int comb(int i,int j){
	
	int temp=1;
	
	if(j==0)
	return temp;
	
	else
	temp=i*comb(i-1,j-1);
	
}

void binary(int n){

if(n==0)
return;

else
binary(n/2);

printf("%d",n%2);

}

bool prime(int n){

int k;

for(k=2;k<=n;k++){

if(n%k==0)
break;

}

return(k==n);

}

