#include <stdio.h>

int time(int a[], int n, int m, int max){
	int days=1;
	int nowtime=0;
	for(int i=0;i<m;i++){
		if (nowtime+a[i]<=max){
			nowtime+=a[i];}
		else{
			days+=1;
			nowtime=a[i];}}
	if (days<=n){
		return days;}
	else 
		return 0;}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[m];
	for(int i=0;i<m;i++){
		scanf("%d",&arr[i]);}
	int beg = arr[0];
	int end=0;
	for (int i=0;i<m;i++){
		end+=arr[i];}
	int result=end;
	while(beg<=end){
		int mid=(beg+end)/2;
		int d=time(arr,n,m,mid);
		if (d){
			result =mid;
			end=mid-1;}
		else{
			beg=mid+1;}}
	printf("%d",result);
	return 1;}		
