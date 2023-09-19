#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	for(int i=0;i<n-1;i++){
		int max=arr[i], pos=i;
		for (int j=i+1;j<n;j++){
			if (max<=arr[j]){
				max=arr[j];
				pos=j;}}
		int temp = arr[i];
        	arr[i] = arr[pos];
        	arr[pos] = temp;}
	for(int i=0;i<n-1;i++){
		printf("%d ",arr[i]);}	
	printf("%d",arr[n-1]);
	return 1;}
