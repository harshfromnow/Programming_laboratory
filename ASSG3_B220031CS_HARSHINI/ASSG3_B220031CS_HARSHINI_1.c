#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	float arr[n];
	for(int i=0;i<n;i++){
		scanf("%f",&arr[i]);}
	int x,d;
	scanf("%d",&x);
	scanf("%d",&d);
	for(int k=n-x;k<n && d>0;k++){
		int j=k-1;
		float temp=arr[k];
		while (j>=0 && temp<=arr[j]){
			arr[j+1]=arr[j];
			j-=1;}
		arr[j+1]=temp;
		d--;}
	for(int i=0;i<n-1;i++){
		printf("%.2f ",arr[i]);}
	printf("%.2f",arr[n-1]);
	return 1;}
