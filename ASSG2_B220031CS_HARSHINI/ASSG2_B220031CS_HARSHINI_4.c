#include <stdio.h>

int check(int a[],int k,int len){
	for(int i=0;i<len;i++){
		if (a[i]==k){
			return i;}}
	return 1;}

int main(){
	int n,k;
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	scanf("%d",&k);
	int result=check(arr,k,n);
	printf("%d",result);
	return 1;
}

