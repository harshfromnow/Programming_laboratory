#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	for(int k=0;k<n;k++){
		int j=k-1;
		int temp=arr[k];
		while (j>=0 && temp<=arr[j]){
			arr[j+1]=arr[j];
			j-=1;}
		arr[j+1]=temp;}
	for(int i=0;i<n-1;i++){
		printf("%d ",arr[i]);}
	printf("%d",arr[n-1]);
	return 1;}
