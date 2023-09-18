#include <stdio.h>

void num(int x){
	if (x>0){
		num(x-1);
		printf("%d ",x);}
	else{
		return;}
}

void main(){
	int n;
	scanf("%d",&n);
	num(n-1);
	printf("%d",n);}
