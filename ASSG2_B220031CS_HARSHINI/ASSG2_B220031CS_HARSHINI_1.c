#include <stdio.h>

int binary(int a[],int beg,int end,int k){
	int kelement=-1;
	while(beg<=end){
		int mid=(beg+end)/2;
		int miss=a[mid]-mid-1;
		if (miss>=k){
			end=mid-1;}
		else{
			beg=mid+1;}
		if (miss>=k){
			kelement=a[mid]-(miss-k+1);}}
	return kelement;}
		

int main(){
 	int n,k;
 	scanf("%d",&n);
 	int arr[n];
 	for(int i=0;i<n;i++){
 		scanf("%d",&arr[i]);}
 	scanf("%d",&k);
 	int result=binary(arr,0,n-1,k);
 	printf("%d",result);
 	return 1;
 	}
