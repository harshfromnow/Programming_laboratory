#include <stdio.h>

int radixsort(int arr[], int n){
	int max=arr[0];
	for (int i=0;i<n;i++){
		if (arr[i]>=max){
			max=arr[i];}
	}
	int digit=1;
	int temp[n];
	int count[10];
	while (max/digit>0){
		for (int i=0;i<10;i++){
			count[i]=0;}
		for (int i=0;i<n;i++){
			if (arr[i]>=0){
				int k=(arr[i]/digit)%10;
				count[k]++;}}
		for (int i=1;i<10;i++){
			count[i]+=count[i-1];}
		for (int i=n-1;i>=0;i--){
			if (arr[i]>=0){
				int k=(arr[i]/digit)%10;
				temp[count[k]-1]=arr[i];
				count[k]--;}}
		for (int i=0;i<n;i++){
			if (arr[i]>=0){
				arr[i]=temp[i];}}
		digit*=10;}
	return 0;}
			

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);}
	radixsort(arr,n);
	for(int i=0;i<n-1;i++){
		printf("%d ",arr[i]);}
	printf("%d",arr[n-1]);
	return 1;
}

