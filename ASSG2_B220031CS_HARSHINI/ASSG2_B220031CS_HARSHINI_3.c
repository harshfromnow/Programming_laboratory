#include <stdio.h>

int binary(int a[],int beg, int end){
	while (beg<=end){
		int mid=(beg+end)/2;
		if (a[mid+1]<a[mid] && a[mid-1]<a[mid])
			return a[mid];
		else if (a[mid]<a[mid+1]) 
			beg=mid+1;
		else
			end=mid-1;}
	return -1;}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	int result=binary(arr,0,n-1);
	printf("%d",result);
	return 1;}
