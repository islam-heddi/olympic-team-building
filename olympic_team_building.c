#include <stdio.h>

int getinput();
int strength(int arr[],int,int);

int main(){
	int n = getinput();
	int t[n];
	int s1=0,s2=0;
	for(int i=0;i<n;i++){
		printf("the player %d please enter a number : ", i+1);
		scanf("%d", &t[i]);
	}
	int start=0,end=(n/2)-1,end1=n-1;
	while(start!=end){
		s1=strength(t,start,end);
		s2=strength(t,end+1,end1);
		if(s1>s2){
			end1=end;
			end=end/2;
		}else if(s2>s1){
			start=end+1;
			end=end+(end1-start)/2;
		}
	}
	printf("the absolute winner is %d with %d score", start+1,t[start]);
	return 0;
}

int getinput(){
	int input;
	do{
		printf("enter the players : ");
		scanf("%d", &input);
	}while(input<=1);
	return input*input;
}

int strength(int arr[],int s,int e){
	int sum=0;
	for(int i=s;i<=e;i++){
		sum=sum+arr[i];
	}
	return sum;
}
