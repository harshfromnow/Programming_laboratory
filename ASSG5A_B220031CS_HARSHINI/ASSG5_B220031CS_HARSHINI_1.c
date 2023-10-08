#include <stdio.h>
	
void MERGE(int A[], int p, int q, int r){
	int l1=q-p+1;
	int l2=r-q;
	int L[l1], R[l2];
	for (int i=0;i<l1;i++){
		L[i]=A[p+i];}
	for (int i=0;i<l2;i++){
		R[i]=A[q+1+i];}
	int i=0,j=0,k=p;
	while (i<l1 && j<l2){
		if (L[i]<=R[j]){
			A[k]=L[i];
			i++;}
		else{
			A[k]=R[j];
			j++;}
		k++;
		}
	while (i<l1){
		A[k]=L[i];
		i++;
		k++;}
	while (j<l2){
		A[k]=R[j];
		j++;
		k++;}
	}
		
void MERGESORT(int arr[], int p, int r){
	if (p<r){
		int q= p+ (r-p)/2;
		MERGESORT(arr,p,q);
		MERGESORT(arr,q+1,r);
		MERGE(arr,p,q,r);
		}
	}
		
void PRINT(int arr[], int n){
	for (int i=0;i<n-1;i++){
		printf("%d ",arr[i]);
		}
	printf("%d",arr[n-1]);
}
	

int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for (int i=0;i<n;i++){
		scanf("%d",&A[i]);}
	MERGESORT(A,0,n-1);
	PRINT(A,n);
	return 1;
}
